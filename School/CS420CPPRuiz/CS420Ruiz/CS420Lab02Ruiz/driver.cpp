#include <iostream>
#include <fstream>
#include <thread>
#include <algorithm>
#include <string>
#include <sstream>
#include <vector>


using namespace std;

// global histogram for use of part 1
long long int gH[256];

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

/*
* 
* read each characters ascii value 
* not the actual value of the text
*/

int main(int argc, char** argv) {
	// get core count, create buffer for file and size for bytes
	const unsigned int THREAD_COUNT = thread::hardware_concurrency();
	size_t bytes;
	vector<thread> workers(THREAD_COUNT);
	char* fileName = argv[1];
	char curr;
	int i = 0;

	ifstream inFile(fileName, ios::in | ios::binary | ios::ate);

	if (!inFile)
	{
		cerr << "Cannot open " << fileName << endl;
		inFile.close();
		exit(1);
	}
	while (!inFile.eof()) {
		inFile >> curr;
		gH[curr]++;
		++i;
	}


	for (int a = 0; a < 255; ++a) {
		cout << gH[a] << endl;
	}

	
}