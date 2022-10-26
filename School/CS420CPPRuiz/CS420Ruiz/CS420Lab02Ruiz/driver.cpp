#include <iostream>
#include <fstream>
#include <thread>
#include <vector>
#include <algorithm>
#include <mutex>

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
	long long unsigned sH[256];
	unsigned count = 0;
	for (unsigned i = 0; i < 256; ++i) { sH[i] = 0; }

	ifstream inFile(fileName, ios::in | ios::binary | ios::ate);
	fileValidation(inFile, fileName);

	inFile.seekg(0, ios::beg);	// go back to offset 0 (start of file)
	unsigned char curr;
	while (inFile.good()) {
		curr = inFile.get();
		sH[curr]++;
	}
	inFile.close();

	for (unsigned i = 0; i < 256; ++i) {
		cout << sH[i] << ": h(" << i << ")" << endl;
	}

}

void globalThreadHistogram(char* fileName, const unsigned int THREAD_COUNT, vector<thread>& workers) {
	size_t bytes;
	unsigned bytesPerThread;
	unsigned remainingBytes;
	long long unsigned gH[256];
	for (unsigned i = 0; i < 256; ++i) { gH[i] = 0; }
	unsigned curr;

	unsigned start = 0;
	unsigned end;

	mutex m;

	ifstream inFile(fileName, ios::in | ios::binary | ios::ate);
	fileValidation(inFile, fileName);

	bytes = inFile.tellg();						// get total number of bytes
	inFile.seekg(0, ios::beg);					// go back to offset 0 (start of file)
	bytesPerThread = bytes / THREAD_COUNT;		
	remainingBytes = bytes % THREAD_COUNT;	// extra bytes for one thread to process
	end = bytesPerThread;						// range for first bytesPerThread bytes set

	for (unsigned i = 1; i <= THREAD_COUNT; ++i) {
		if (i == THREAD_COUNT) {
			end += remainingBytes;
		}


		workers.push_back(thread([&m, &gH, &inFile](unsigned start, unsigned end) {
			lock_guard<mutex> lg(m);
			inFile.seekg(start, ios::beg);
			unsigned char curr;
			for (unsigned j = start; j < end; ++j) {
				curr = inFile.get();
				gH[curr]++;
			}
		}, start, end));

		start = end;
		end = start + bytesPerThread;

	}

	// enable all threads
	for_each(workers.begin(), workers.end(), [](thread& t) { 
		t.join(); 
	});


	inFile.close();

	for (unsigned i = 0; i < 256; ++i) {
		cout << gH[i] << ": gH(" << i << ")" << endl;
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
	fileValidation(inFile, fileName);

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

			m.lock();
			inFile.seekg(start, ios::beg);
			unsigned char curr;
			for (unsigned j = start; j < end; ++j) {
				curr = inFile.get();
				h[curr]++;
			}

			m.unlock();
			}, start, end));

		start = end;
		end = start + bytesPerThread;

	}



	inFile.close();


}

int main(int argc, char** argv) {
	
	const unsigned int THREAD_COUNT = thread::hardware_concurrency();		// get core count
	vector<thread> workers;													// will hold the worker threads that will read the file
	char* fileName = argv[1];												// gets the file name;
	
	cout << "Sequential Histogram: " << endl;								// sequential reading of the file into histogram
	sequentialHistogram(fileName);
	cout << endl << endl;


	cout << "Run with one global histogram: " << endl;						// thread processing of the file with a global histogram
	globalThreadHistogram(fileName, THREAD_COUNT, workers);
	cout << endl << endl;

	workers.clear();
	cout << "Run with local histograms: " << endl;
	localThreadHistogram(fileName, THREAD_COUNT, workers);
	cout << endl;

}