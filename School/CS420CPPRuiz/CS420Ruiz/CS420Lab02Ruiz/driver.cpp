#include <iostream>
#include <fstream>
#include <thread>
#include <algorithm>
#include <string>
#include <sstream>
#include <vector>


using namespace std;

// global histogram for use of part 1

/*
* 
* read each characters ascii value 
* not the actual value of the text
*/

int main(int argc, char** argv) {
	// get core count, create buffer for file and size for bytes
	const unsigned int THREAD_COUNT = thread::hardware_concurrency();
	unsigned int bytesPerThread;
	unsigned int remainingBytes;
	long long int gH[256];
	int start = 0;
	int end;

	
	size_t bytes;
	vector<thread> workers;
	char* fileName = argv[1];
	


	ifstream inFile(fileName, ios::in | ios::binary | ios::ate);

	if (!inFile)
	{
		cerr << "Cannot open " << fileName << endl;
		inFile.close();
		exit(1);
	}


	bytes = inFile.tellg();		// get total number of bytes
	inFile.seekg(0, ios::beg);	// go back to offset 0 (start of file)
	bytesPerThread = bytes / THREAD_COUNT;
	remainingBytes = bytes % bytesPerThread;
	end = bytesPerThread;		// first n bytes set
	
	for (int i = 1; i <= THREAD_COUNT; ++i) {
		if (i == THREAD_COUNT) {
			end += remainingBytes;
		}


		workers.push_back(thread([gH](ifstream inFile, int start, int end) {
			char curr;

			curr = inFile.get();
			while (inFile.good()) {
				gH[curr]++;
				curr = inFile.get();
			}


		}, inFile, start, end));
		
		start = end;
		end = start + bytesPerThread;

	}
	
	
	for_each(workers.begin(), workers.end(), [](thread& t)
		{
			t.join();
		}
	);
	

	
	inFile.close();

	for (int i = 0; i < 256; ++i) {
		cout << gH[i] << ": h(" << i << ")" << endl;
	}
}