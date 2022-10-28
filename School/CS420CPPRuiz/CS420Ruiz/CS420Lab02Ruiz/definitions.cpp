#include <iostream>
#include <fstream>
#include <thread>
#include <mutex>
#include <algorithm>
#include <vector>

using namespace std;



/*
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
*/

void sequentialHistogram(char* fileName) {
	long long unsigned sH[256];
	unsigned count = 0;
	for (unsigned i = 0; i < 256; ++i) { sH[i] = 0; }

	ifstream inFile(fileName, ios::in | ios::binary | ios::ate);

	inFile.seekg(0, ios::beg);	// go back to offset 0 (start of file)
	unsigned char curr;
	while (inFile.good() && !inFile.eof()) {
		curr = inFile.get();
		sH[curr]++;
	}
	inFile.close();

	for (unsigned i = 0; i < 256; ++i) {
		cout << sH[i] << ": h(" << i << ")" << endl;
	}

}


void localThreadHistogram(char* fileName, const unsigned int THREAD_COUNT, vector<thread>& workers) {
	long long unsigned h[256];
	size_t bytes;
	unsigned bytesPerThread;
	unsigned remainingBytes;

	unsigned curr;

	unsigned start = 0;
	unsigned end;

	mutex m;

	ifstream inFile(fileName, ios::in | ios::binary | ios::ate);

	bytes = inFile.tellg();						// get total number of bytes
	inFile.seekg(0, ios::beg);					// go back to offset 0 (start of file)
	bytesPerThread = bytes / THREAD_COUNT;
	remainingBytes = bytes % THREAD_COUNT;	// extra bytes for one thread to process
	end = bytesPerThread;						// range for first bytesPerThread bytes set

	for (unsigned i = 1; i <= THREAD_COUNT; ++i) {
		if (i == THREAD_COUNT) {
			end += remainingBytes;
		}


		workers.push_back(thread([&m, &inFile](unsigned start, unsigned end) {
			long long unsigned h[256];
			for (unsigned i = 0; i < 256; ++i) { h[i] = 0; }

			// lock file to prevent seekg moving file pointer somewhere unwanted
			unsigned char curr;
			for (unsigned j = start; j < end; ++j) {
				lock_guard<mutex> lg(m);
				inFile.seekg(start, ios::beg);
				curr = inFile.get();
				h[curr]++;
			}


			}, start, end));

		start = end;
		end = start + bytesPerThread;

	}
	inFile.close();


}
