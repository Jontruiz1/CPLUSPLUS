#include "definitions.h"

void globalHistogram(const unsigned MAX, const unsigned THREAD_COUNT, const char* data, unsigned long long int* gH, const size_t& bytes, vector<thread>& workers) {
	// initialize start, end points as well as bytes per thread count
	unsigned block = bytes / THREAD_COUNT;
	unsigned extra = bytes % THREAD_COUNT;
	unsigned start = 0;
	unsigned end = block;
	mutex m;
	
	// for each thread that we'll initialize
	for (unsigned i = 1; i <= THREAD_COUNT; ++i) {
		// if final thread make sure we take care of potential extra bytes
		if (i == THREAD_COUNT) {
			end += extra;
		}
		// assign worker threads their functions
		workers.push_back(thread([data, &m, &gH](const unsigned int& start, const unsigned int& end) {
			unsigned char curr;
			for (unsigned j = start; j < end; ++j) {
				m.lock();
				curr = data[j];
				gH[curr]++;
				m.unlock();
			}

		}, start, end));
		start = end;
		end = start + block;
	}

	// threads come home
	for_each(workers.begin(), workers.end(), [](thread& t) { t.join(); });

	for (unsigned i = 0; i < MAX; ++i) {
		cout << i << ": " << gH[i] << endl;
	}

}
void localHistogram(const unsigned MAX, const unsigned THREAD_COUNT, const char* data, unsigned long long int* gH, const size_t& bytes, vector<thread>& workers) {
	unsigned block = bytes / THREAD_COUNT;
	unsigned extra = bytes % THREAD_COUNT;
	unsigned start = 0;
	unsigned end = block;

	for (unsigned i = 1; i <= THREAD_COUNT; ++i) {
		if (i == THREAD_COUNT) {
			end += extra;
		}

		workers.push_back(thread([data, i, gH](unsigned start, unsigned end, const unsigned MAX) {
			unsigned char curr;							// current character
			unsigned offset = (i - 1) * MAX;			// offset for each local histogram

			for (unsigned j = start; j < end; ++j) {
				curr = data[j];
				gH[offset + curr]++;
			}

			}, start, end, MAX));
		start = end;
		end = start + block;
	}

	// threads come home
	for_each(workers.begin(), workers.end(), [](thread& t) { t.join(); });

	// accumulate local histograms into the global histogram
	for (unsigned i = 0; i < MAX; ++i) {
		unsigned curr = 0;

		// jth hit count in each threads local histogram and keeping a running total
		for (unsigned j = 0; j < THREAD_COUNT; ++j) {
			curr += gH[(j * MAX) + i];
		}

		// reassign whatever the current ascii value's hit counts to whatever the running total is
		gH[i] = curr;
	}

	for (unsigned i = 0; i < MAX; ++i) {
		cout << i << ": " << gH[i] << endl;
	}
}


void sequentialHistogram(const unsigned MAX, const char* data, const size_t& bytes) {

	unsigned* sH = new unsigned[MAX];
	for (unsigned i = 0; i < MAX; ++i) {
		sH[i] = 0;
	}

	for (unsigned i = 0; i < bytes; ++i) {
		sH[(unsigned char)data[i]]++;
	}

	for (unsigned i = 0; i < MAX; ++i) {
		cout << i << ": " << sH[i] << endl;
	}

	delete[] sH;
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