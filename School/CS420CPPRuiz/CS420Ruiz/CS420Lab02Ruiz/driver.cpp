#include <iostream>
#include <fstream>
#include <thread>
#include <vector>
#include <algorithm>

using namespace std;

void fileValidation(ifstream& inFile, char* fileName) {

	if (!inFile)
	{
		cerr << "Cannot open " << fileName << endl;
		inFile.close();
		exit(1);
	}
}

void sequentialHistogram(char* fileName) {
	long long int sH[256];
	for (int i = 0; i < 256; ++i) { sH[i] = 0; }

	ifstream inFile(fileName, ios::in | ios::binary | ios::ate);
	fileValidation(inFile, fileName);

	inFile.seekg(0, ios::beg);	// go back to offset 0 (start of file)
	char curr;
	curr = inFile.get();
	while (inFile.good()) {
		sH[curr]++;
		curr = inFile.get();
	}
	inFile.close();

	for (int i = 0; i < 256; ++i) {
		cout << sH[i] << ": h(" << i << ")" << endl;
	}


}

void globalThreadHistogram(char* fileName, const unsigned int THREAD_COUNT, vector<thread>& workers) {
	size_t bytes;
	unsigned int bytesPerThread;
	unsigned int remainingBytes;
	long long int gH[256];
	for (int i = 0; i < 256; ++i) { gH[i] = 0; }
	char curr;

	int start = 0;
	int end;

	ifstream inFile(fileName, ios::in | ios::binary | ios::ate);
	fileValidation(inFile, fileName);

	bytes = inFile.tellg();						// get total number of bytes
	inFile.seekg(0, ios::beg);					// go back to offset 0 (start of file)
	bytesPerThread = bytes / THREAD_COUNT;		
	remainingBytes = bytes % THREAD_COUNT;	// extra bytes for one thread to process
	end = bytesPerThread;						// range for first bytesPerThread bytes set

	for (int i = 1; i <= THREAD_COUNT; ++i) {
		if (i == THREAD_COUNT) {
			end += remainingBytes;
		}


		workers.push_back(thread([&gH, &inFile](int start, int end, char curr) {
			
			
			for (int j = start; j < end; ++j) {
				curr = inFile.get();
				gH[curr]++;
			}


			}, start, end, curr));

		start = end;
		end = start + bytesPerThread;

	}

	// enable all threads
	for_each(workers.begin(), workers.end(), [](thread& t) { 
		t.join(); 
	});


	inFile.close();

	for (int i = 0; i < 256; ++i) {
		cout << gH[i] << ": gH(" << i << ")" << endl;
	}
}


int main(int argc, char** argv) {
	
	const unsigned int THREAD_COUNT = thread::hardware_concurrency();		// get core count, create buffer for file and size for bytes
	vector<thread> workers;													// will hold the worker threads that will read the file
	char* fileName = argv[1];												// gets the file name;
	
	//cout << "Sequential Histogram: " << endl;								// sequential reading of the file along with the histogram
	//sequentialHistogram(fileName);
	//cout << endl << endl;


	cout << "Run with one global histogram: " << endl;						// thread processing of the file along with a global histogram
	globalThreadHistogram(fileName, THREAD_COUNT, workers);
	cout << endl << endl;


	cout << "Run with local histograms: " << endl;

}