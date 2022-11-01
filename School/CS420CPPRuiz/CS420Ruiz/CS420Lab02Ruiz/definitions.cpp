#include "definitions.h"

void globalHistogram(const unsigned MAX, const unsigned THREAD_COUNT, const char* data, unsigned int* gH, const size_t& bytes, vector<thread>& workers) {
	unsigned bytesPerThread = bytes / THREAD_COUNT;
	unsigned extra = bytes % THREAD_COUNT;
	unsigned start = 0;
	unsigned end = bytesPerThread;
	mutex m;

	for (unsigned i = 1; i <= THREAD_COUNT; ++i) {
		if (i == THREAD_COUNT) {
			end += extra;
		}

		workers.push_back(thread([&m, data, gH](unsigned start, unsigned end) {
			unsigned char curr;

			for (unsigned j = start; j < end; ++j) {
				m.lock();
				curr = data[j];
				gH[curr]++;
				m.unlock();
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
void localHistogram(const unsigned MAX, const unsigned THREAD_COUNT, const char* data, unsigned int* gH, const size_t& bytes, vector<thread>& workers) {
	unsigned bytesPerThread = bytes / THREAD_COUNT;
	unsigned extra = bytes % THREAD_COUNT;
	unsigned start = 0;
	unsigned end = bytesPerThread;
	mutex m;

	for (unsigned i = 1; i <= THREAD_COUNT; ++i) {
		if (i == THREAD_COUNT) {
			end += extra;
		}

		workers.push_back(thread([&m, data, i, gH](unsigned start, unsigned end, const unsigned MAX) {
			unsigned char curr;

			for (unsigned j = start; j < end; ++j) {
				m.lock();
				curr = data[j];
				gH[(i - 1) * MAX + curr]++;
				m.unlock();
			}

			}, start, end, MAX));
		start = end;
		end = start + bytesPerThread;

	}

	// barrier
	for_each(workers.begin(), workers.end(), [](thread& t) { t.join(); });

	// accumulate local histograms into the global histogram
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

void sequentialHistogram(const unsigned MAX, const char* data, const size_t& bytes) {

	long long unsigned* sH = new long long unsigned[MAX];
	for (unsigned i = 0; i < MAX; ++i) {
		sH[i] = 0;
	}

	for (int i = 0; i < bytes; ++i) {
		unsigned char curr = data[i];
		sH[curr]++;
	}

	for (unsigned i = 0; i < MAX; ++i) {
		cout << sH[i] << ": h(" << i << ")" << endl;
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