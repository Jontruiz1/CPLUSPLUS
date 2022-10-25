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

void globalHistogram(char** buffer, const size_t& bytes, const unsigned int THREAD_COUNT) {
	long long int data[256];
	unsigned int i = 0;
	unsigned int bytesPerThread;

	stringstream ss(*buffer);
	string token;
	
	
	while (getline(ss, token, ' ')) { data[i] = stoi(token); i++; }

	for (int a = 0; a < i; ++a) {
		gH[data[a]]++;
	}
	for (int j = 0; j < 256; ++j) {
		cout << gH[j] << ": h(" << j << ")" << endl;
	}
}


int main(int argc, char** argv) {
	// get core count, create buffer for file and size for bytes
	const unsigned int THREAD_COUNT = thread::hardware_concurrency();
	
	char* buffer[256];
	size_t bytes;
	vector<thread> workers(THREAD_COUNT);

	fileToMemoryTransfer(argv[1], buffer, bytes);
	globalHistogram(buffer, bytes, THREAD_COUNT);


	
}