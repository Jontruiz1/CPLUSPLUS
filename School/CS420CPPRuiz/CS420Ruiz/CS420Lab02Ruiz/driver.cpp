#include <vector>
#include <mutex>
#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

const int MAX = 256;
long long unsigned gH[MAX];

void sequentialHistogram(char* fileName) {
	long long unsigned sH[MAX];
	for (int i = 0; i < 256; ++i) {
		sH[i] = 0;
	}
	unsigned char curr;
	size_t bytes;
	mutex m;

	ifstream inFile(fileName, ios::in | ios::binary | ios::ate);
	bytes = inFile.tellg();						// get total number of bytes
	char* data = new char[bytes];
	inFile.seekg(0, ios::beg);					// go back to offset 0 (start of file)
	inFile.read(data, bytes);
	inFile.seekg(0, ios::beg);	// go back to offset 0 (start of file)

	inFile.close();

	for (int i = 0; i < bytes; ++i) {
		curr = data[i];
		sH[curr]++;
	}

	for (unsigned i = 0; i < 256; ++i) {
		cout << sH[i] << ": h(" << i << ")" << endl;
	}

}

void globalThreadHistogram(char* fileName, const unsigned int THREAD_COUNT, vector<thread>& workers) {
	size_t bytes;
	size_t bytesPerThread;
	unsigned remainingBytes;
	unsigned start = 0;
	unsigned end;
	mutex m;
	

	ifstream inFile(fileName, ios::in | ios::binary | ios::ate);

	bytes = inFile.tellg();						// get total number of bytes
	char* data = new char[bytes];
	inFile.seekg(0, ios::beg);					// go back to offset 0 (start of file)
	inFile.read(data, bytes);
	bytesPerThread = bytes / THREAD_COUNT;
	remainingBytes = bytes % THREAD_COUNT;		// extra bytes for one thread to process
	end = bytesPerThread;						// range for first bytesPerThread bytes set

	for (unsigned i = 1; i <= THREAD_COUNT; ++i) {
		if (i == THREAD_COUNT) {
			end += remainingBytes;
		}
		workers.push_back(thread([&data, &m, &inFile](unsigned start, unsigned end) {

			for (unsigned j = start; j < end; ++j) {
				unsigned char curr = data[j];
				lock_guard<mutex> lg(m);
				gH[curr]++;
			}

		}, start, end));

		start = end;
		end = start + bytesPerThread;

	}

	// prevents main thread from finishing before threads finish running
	for_each(workers.begin(), workers.end(), [](thread& t) { t.join(); });
	inFile.close();

	for (unsigned i = 0; i < MAX; ++i) {
		cout << gH[i] << ": h(" << i << ")" << endl;
	}
}

int main(int argc, char** argv) {
	
	const unsigned int THREAD_COUNT = thread::hardware_concurrency();		// get core count
	vector<thread> workers;													// will hold the worker threads that will read the file
	char* fileName = argv[1];												// gets the file name;

	cout << "Sequential Histogram: " << endl;								// sequential reading of the file into histogram
	sequentialHistogram(fileName);
	cout << endl;
	
	cout << "Run with one global histogram: " << endl;						// thread processing of the file with a global histogram
	globalThreadHistogram(fileName, THREAD_COUNT, workers);
	cout << endl;

	workers.clear();

	
	cout << "Run with local histograms: " << endl;
	//localThreadHistogram(fileName, THREAD_COUNT, workers);
	cout << endl;
	

}