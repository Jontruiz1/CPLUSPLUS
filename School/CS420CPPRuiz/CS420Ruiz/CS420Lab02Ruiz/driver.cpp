/* CS420Lab02Ruiz
* 
* I organized the definitions into a separate header and cpp file because it got tiresome to look at
* 
*/
#include "definitions.h"

int main(int argc, char** argv) {
	const unsigned MAX = 256;													// ascii value maxes
	const unsigned THREAD_COUNT = thread::hardware_concurrency();				// thread count of current machine
	const unsigned ARRAY_MAX = MAX * THREAD_COUNT;
	unsigned long long int* gH = new unsigned long long int[ARRAY_MAX];											// the global histogram that will hold all the both the global design and local design

	
	for (unsigned i = 0; i < ARRAY_MAX; ++i) { gH[i] = 0; }							// initialize the global arrays values
	char* data[1];
	vector<thread> workers;															// will hold the worker threads that will read the file
	size_t bytes;

	fileToMemoryTransfer(argv[1], data, bytes);										// read the file into buffer
	
	cout << "Sequential Histogram: " << endl;										// sequential reading of the file into histogram, just for testing purposes
	sequentialHistogram(MAX, *data, bytes);
	cout << endl;
	
	cout << "Run with one global histogram" << endl;								// thread processing of the file with a global histogram
	globalHistogram(MAX, THREAD_COUNT, *data, gH, bytes, workers);
	workers.clear();																// clear the threads in the workers
	
	for (int i = 0; i < MAX; ++i) { gH[i] = 0; }									// only up to 256 should have been used for the global histogram, reset it

	cout << "Run with local histograms" << endl;
	localHistogram(MAX, THREAD_COUNT, *data, gH, bytes, workers);					// thread processing of the file with a local histogram
	
	delete[] gH;																	// clear up the arrays memory
}


