/* CS420Lab02Ruiz
* 
* I organized the definitions into a separate header and cpp file because it got tiresome
* to look at all my definitions. I also was using a couple extra functions to test some things so I figured 
* I would keep them in
* 
*/
#include "definitions.h"


int main(int argc, char** argv) {
	const unsigned MAX = 256;														// ascii value maxes
	const unsigned THREAD_COUNT = thread::hardware_concurrency();
	atomic<unsigned int*> gH = new unsigned int[MAX * THREAD_COUNT];				// the global histogram that will hold all the both the global design and local design

	// initialize the global arrays values
	for (int i = 0; i < MAX * THREAD_COUNT; ++i) { gH[i] = 0; }
	char* data[1];
	vector<thread> workers;															// will hold the worker threads that will read the file
	size_t bytes;

	fileToMemoryTransfer(argv[1], data, bytes);										// read the file into buffer
	
	cout << "Sequential Histogram: " << endl;								// sequential reading of the file into histogram, just for testing purposes
	sequentialHistogram(MAX, *data, bytes);
	cout << endl;
	
	/*
	cout << "Run with one global histogram" << endl;								// thread processing of the file with a global histogram
	globalHistogram(MAX, THREAD_COUNT, *data, gH, bytes, workers);
	workers.clear();																// clear the threads in the workers
	cout << endl;

	for (int i = 0; i < MAX; ++i) { gH[i] = 0; }									// reset the global histogram

	cout << "Run with local histograms" << endl;
	localHistogram(MAX, THREAD_COUNT, *data, gH, bytes, workers);					// thread processing of the file with a local histogram
	*/
	delete[] gH;
}


