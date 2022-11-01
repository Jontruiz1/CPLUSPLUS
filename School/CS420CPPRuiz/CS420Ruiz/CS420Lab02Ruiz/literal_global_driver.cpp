#include <vector>
#include <mutex>
#include <algorithm>
#include <iostream>
#include <fstream>

using namespace std;

const unsigned MAX = 256;
const unsigned THREAD_COUNT = thread::hardware_concurrency();
unsigned int* gH = new unsigned int[MAX * THREAD_COUNT];

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

	for (unsigned i = 0; i < MAX; ++i) {
		cout << sH[i] << ": h(" << i << ")" << endl;
	}
}

void globalHistogram(const char* data, const size_t& bytes, vector<thread>& workers ) {
	unsigned bytesPerThread = bytes / THREAD_COUNT;
	unsigned extra = bytes % THREAD_COUNT;
	unsigned start = 0;
	unsigned end = bytesPerThread;
	mutex m;
	

	for (unsigned i = 1; i <= THREAD_COUNT; ++i) {
		if (i == THREAD_COUNT) {
			end += extra;
		}

		workers.push_back(thread([&m, data]( unsigned start, unsigned end) {
			unsigned char curr;

			for (unsigned j = start; j < end; ++j) {
				lock_guard<mutex> lg(m);
				curr = data[j];
				gH[curr]++;
			}
		}, start, end));
		start = end;
		end = start + bytesPerThread;

	}

	for_each(workers.begin(), workers.end(), [](thread& t) {
		t.join();
	});

	for (unsigned i = 0; i < MAX; ++i) {
		cout << gH[i] << ": h(" << i << ")" << endl;
	}

}

void localHistogram(const char* data, const size_t& bytes,  vector<thread>& workers) {
	unsigned bytesPerThread = bytes / THREAD_COUNT;
	unsigned extra = bytes % THREAD_COUNT;
	unsigned start = 0;
	unsigned end = bytesPerThread;
	mutex m;

	for (unsigned i = 1; i <= THREAD_COUNT; ++i) {
		if (i == THREAD_COUNT) {
			end += extra;
		}

		workers.push_back(thread([&m, data, i](unsigned start, unsigned end) {
			unsigned char curr;

			for (unsigned j = start; j < end; ++j) {
				lock_guard<mutex> lg(m);
				curr = data[j];
				gH[(i-1) * MAX + curr]++;
			}

		}, start, end));
		start = end;
		end = start + bytesPerThread;

	}

	// barrier
	for_each(workers.begin(), workers.end(), [](thread& t) { t.join(); });
	
	for (unsigned i = 0; i < MAX; ++i) {
		unsigned curr = 0;
		for (unsigned j = 0; j < THREAD_COUNT; ++j) {
			curr += gH[(j * MAX) + i];
		}
		gH[i] = curr;
	}

	for (unsigned i = 0; i < MAX; ++i) {
		cout << gH[i] << ": h(" << i << ")" << endl;
	}
}

int main(int argc, char** argv) {
	for (int i = 0; i < MAX * THREAD_COUNT; ++i) {
		gH[i] = 0;
	}
	char* fileName = argv[1];												// gets the file name;
	char* buffer[1];
	vector<thread> workers;													// will hold the worker threads that will read the file
	size_t bytes;

	fileToMemoryTransfer(fileName, buffer, bytes);							// read the file into buffer

	
	cout << "Sequential Histogram: " << endl;								// sequential reading of the file into histogram
	clock_t stopTime = clock();
	sequentialHistogram(*buffer, bytes);
	clock_t startTime = clock();
	cout << endl;
	double time = (double(stopTime) - double(startTime)) / CLOCKS_PER_SEC;
	cout << "Sequential Time: " << time << endl << endl;

	cout << "Run with one global histogram: " << endl;						// thread processing of the file with a global histogram
	startTime = clock();
	globalHistogram(*buffer, bytes, workers);
	stopTime = clock();
	cout << endl;
	time = (double(stopTime) - double(startTime)) / CLOCKS_PER_SEC;
	cout << "Global Time: " << time << endl << endl;

	workers.clear();

	for (int i = 0; i < MAX * THREAD_COUNT; ++i) { gH[i] = 0; }

	cout << "Run with local histograms: " << endl;
	startTime = clock();
	localHistogram(*buffer, bytes, workers);
	stopTime = clock();
	cout << endl;
	time = (double(stopTime) - double(startTime)) / CLOCKS_PER_SEC;
	cout << "Local Time: " << time << endl << endl;

}