#include "definitions.h"

int main(int argc, char** argv) {
	const unsigned MAX = 256;
	const unsigned THREAD_COUNT = thread::hardware_concurrency();			// global 
	unsigned int* gH = new unsigned int[MAX * THREAD_COUNT];

	// initialize the global arrays values
	for (int i = 0; i < MAX * THREAD_COUNT; ++i) { gH[i] = 0; }
	char* fileName = argv[1];												// gets the file name;
	char* buffer[1];
	vector<thread> workers;													// will hold the worker threads that will read the file
	size_t bytes;

	fileToMemoryTransfer(fileName, buffer, bytes);							// read the file into buffer

	/*
	cout << "Sequential Histogram: " << endl;								// sequential reading of the file into histogram, just for testing purposes
	sequentialHistogram(MAX, *buffer, bytes);
	cout << endl;
	*/

	cout << "Run with one global histogram" << endl;						// thread processing of the file with a global histogram
	globalHistogram(MAX, THREAD_COUNT, *buffer, gH, bytes, workers);
	workers.clear();														// clear the threads in the workers
	cout << endl;

	for (int i = 0; i < MAX; ++i) { gH[i] = 0; }							// reset the bytes used for the global histogram

	cout << "Run with local histograms" << endl;
	localHistogram(MAX, THREAD_COUNT, *buffer, gH, bytes, workers);

	delete[] gH;
}


