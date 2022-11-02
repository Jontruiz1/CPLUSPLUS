#include <iostream>
#include <fstream>
#include <thread>
#include <vector>
#include <algorithm>
#include <mutex>

using namespace std;

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

//********************************************* GLOBAL HISTOGRAM *************************************************
int globalHistogram(int argc, char** argv) {

	//variables
	char* inData;	//for the data being read
	size_t size;	//for the numOfBytes assinged
	fileToMemoryTransfer(argv[1], &inData, size);	//calling of fileToMemoryTransfer function	// (char*) in front of argv[1]

	vector<size_t> N(256, 0);	//0 to 255
	vector<thread> workers;	//vector of workers threads
	int _numThreads = thread::hardware_concurrency();  //number of cores

	mutex l;	//for locking THIS WAS ALSO CHANGED<<<<<<<<<<<<<<<<<<<<<<<<<<

	int rows = size / _numThreads;
	int extra = size % _numThreads;
	int start = 0;    // row dimensions for first thread
	int end = rows;


	for (int t = 1; t <= _numThreads; t++) {
		if (t == _numThreads) // last thread processes any extra rows
			end += extra;

		workers.push_back(thread([&l, start, end, &inData, &N]() {
			for (int i = start; i < end; i++) {
				lock_guard<mutex> lg(l);	//locks l in constructor and unlocks l destructor	//THIS IS ONE CHANGE<<<<<<<<<<<<<<<<<<<<<<<<<<
				N[(unsigned char)inData[i]]++;	//CHANGE TO ADD THE UNSIGNED CHAR<<<<<<<<<<<<<<<<<<<<<<<<<<
			}
			})//end of thread
		);//end of workers.push_back
		start = end;
		end = start + rows;
	}

	for_each(workers.begin(), workers.end(), [](thread& t) {
		t.join();	//barrier that joins all the threads
		});	//end of for_each

	cout << "Run with one global histogram" << endl;	//indicator that the following is the results

	for (size_t i = 0; i < N.size(); i++) {	//loop that prints out the numbers
		cout << i << ": " << N[i] << endl;
	}

	return 0;
}

//************************************************* LOCAL HISTOGRAM *****************************************************
int localHistogram(int argc, char** argv) {


	cout << "\nRun with one local histogram" << endl;	//indicator that the following is the results


	return 0;
}

int main(int argc, char** argv) {
	globalHistogram(argc, argv);
	localHistogram(argc, argv);

}