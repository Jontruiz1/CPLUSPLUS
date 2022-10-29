#include <vector>
#include <mutex>
#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

const int MAX = 256;
long long unsigned gH[MAX];

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

void sequentialHistogram(const char *data, const size_t& bytes) {
	long long unsigned sH[MAX] = { 0 };
	unsigned char curr;
	mutex m;

	for (int i = 0; i < bytes; ++i) {
		curr = data[i];
		sH[curr]++;
	}

	for (unsigned i = 0; i < 256; ++i) {
		cout << sH[i] << ": h(" << i << ")" << endl;
	}
}


void globalHistogram(const char* data, const size_t& bytes, const unsigned int& THREAD_COUNT, vector<thread>& workers ) {
	unsigned bytesPerThread = bytes / THREAD_COUNT;
	unsigned extra = bytes % THREAD_COUNT;
	unsigned start = 0;
	unsigned end = bytesPerThread;
	mutex m;
	

	for (unsigned i = 1; i <= THREAD_COUNT; ++i) {
		if (i == THREAD_COUNT) {
			end += extra;
		}

		workers.push_back(thread([&m](const char* data, unsigned start, unsigned end) {
			unsigned char curr;

			for (unsigned j = start; j < end; ++j) {
				lock_guard<mutex> lg(m);
				curr = data[j];
				gH[curr]++;
			}
		}, data, start, end));
		start = end;
		end = start + bytesPerThread;

	}

	for_each(workers.begin(), workers.end(), [](thread& t) {
		t.join();
	});

	for (unsigned i = 0; i < 256; ++i) {
		cout << gH[i] << ": h(" << i << ")" << endl;
	}

}

int main(int argc, char** argv) {
	
	const unsigned int THREAD_COUNT = thread::hardware_concurrency();		// get core count
	char* fileName = argv[1];												// gets the file name;
	char* buffer[256];
	vector<thread> workers;													// will hold the worker threads that will read the file
	size_t bytes;

	fileToMemoryTransfer(fileName, buffer, bytes);

	cout << "Sequential Histogram: " << endl;								// sequential reading of the file into histogram
	sequentialHistogram(*buffer, bytes);
	cout << endl;
	
	cout << "Run with one global histogram: " << endl;						// thread processing of the file with a global histogram
	globalHistogram(*buffer, bytes, THREAD_COUNT, workers);
	cout << endl;

	workers.clear();

	
	cout << "Run with local histograms: " << endl;
	//localThreadHistogram(fileName, THREAD_COUNT, workers);
	cout << endl;
	

}