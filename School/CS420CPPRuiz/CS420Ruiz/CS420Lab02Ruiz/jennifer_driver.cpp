#include<iostream> 
#include<string> 
#include<fstream> 
#include<vector> 
#include<thread> 
#include<mutex> 
#include <algorithm>


using namespace std; 

void fileToMemoryTransfer(char* fileName, char** data, size_t& numOfBytes); 

int main(int argc, char** argv) {
	const unsigned int THREAD_NUM = thread::hardware_concurrency(); 
	const unsigned int CHAR_MAXIMUM = 256; 
    unsigned int ghSize = THREAD_NUM * CHAR_MAXIMUM;


	char* buffer[CHAR_MAXIMUM];
	size_t bytes; 
	vector<thread> workers; 
	

	fileToMemoryTransfer(argv[1], buffer, bytes);

	unsigned blockOfBytes = bytes / THREAD_NUM;
	unsigned extra = bytes % THREAD_NUM;
	unsigned start = 0;
	unsigned end = blockOfBytes;


	//Global Histogram 
	vector<int> globalHisto(CHAR_MAXIMUM, 0);
	mutex m; 


	
	for (unsigned t = 1; t <= THREAD_NUM; t++)
	{
		if (t == THREAD_NUM) // last thread processes any extra blockOfBytes:
			end += extra;

	
		workers.push_back(thread([&m, &globalHisto](int start, int end, const char* buffer)
			{
				unsigned char data; 
				for (unsigned i = start; i < end; i++) {
					lock_guard<mutex> lg(m);
					data = buffer[i]; 
					globalHisto.at(data)++;
				}

			}, start, end, *buffer)
		);

		start = end; 
		end = start + blockOfBytes;

		
	}

	for_each(workers.begin(), workers.end(), [](thread& t)
		{
			t.join();
		}
	);

	for (unsigned i = 0; i < CHAR_MAXIMUM; i++) {
		cout << i << ":" << globalHisto.at(i) << endl;

	}

	workers.clear(); 

	//Local Histogram 
	

	cout << endl; 

	vector<int> localHisto(ghSize, 0);


	blockOfBytes = bytes / THREAD_NUM;
	extra = bytes % THREAD_NUM;
	start = 0;
	end = blockOfBytes;

	for (unsigned t = 1; t <= THREAD_NUM; t++)
	{
		if (t == THREAD_NUM) // last thread processes any extra blockOfBytes:
			end += extra;

		//int offset = t * CHAR_MAXIMUM; 

		workers.push_back(thread([ &localHisto, t ](int start, int end, const char* buffer)
			{
				
				unsigned char data;
				for (unsigned i = start; i < end; i++) {
					data = buffer[i]; 
					localHisto.at(data + (t * CHAR_MAXIMUM))++;
				}

			}, start, end,*buffer )
		);

		start = end;
		end = start + blockOfBytes;



	}

	for_each(workers.begin(), workers.end(), [](thread& t)
		{
			t.join();
		}
	);


	for (unsigned i = 0; i < CHAR_MAXIMUM; i++) {
		unsigned curr = 0;
		for (unsigned k = 0; k < THREAD_NUM; ++k) {
			curr += localHisto[(k * CHAR_MAXIMUM) + i];


		}
		localHisto[i] = curr;
	}

	for (unsigned i = 0; i < CHAR_MAXIMUM; i++) {
		globalHisto[i] += localHisto[i];
		cout << i << ":" << localHisto[i] << endl;

	}
	
	return 0; 
}


void fileToMemoryTransfer(char* fileName, char** data, size_t& numOfBytes) {
	streampos begin, end;
	ifstream inFile(fileName, ios::in | ios::binary | ios::ate);
	if (!inFile)
	{
		cerr << "Cannot open " << fileName << endl;
		inFile.close();
		exit(1);
	}
	size_t size = inFile.tellg();
	char* buffer = new  char[size];
	inFile.seekg(0, ios::beg);
	inFile.read(buffer, size);
	inFile.close();
	*data = buffer;
	numOfBytes = size;

}