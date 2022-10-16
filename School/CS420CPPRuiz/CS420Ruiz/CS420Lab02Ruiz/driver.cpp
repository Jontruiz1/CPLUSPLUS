#include <iostream>
#include <fstream>
#include <thread>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

long long int gH[255];

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


void globalHistogramOnly() {
	char fileName[] = "File1.txt";
	char* buffer[256];
	size_t bytes;
	string strbuffer;
	long long int data[255];
	

	fileToMemoryTransfer(fileName, buffer, bytes);
	strbuffer = *buffer;
	while (getline(strbuffer, '\n')) {

	}

	// once you get the bytes you gotta divide the theads amongst these bytes evenly.

	//cout << strbuffer[bytes-1];

	//cout << "Run with one global histogram" << endl;
	//// probably start a thread now
	//for (int i = 0; i < 256; ++i) {
	//	cout << gH[i] << ": h(" << i << ")" << endl;
	//}


}

int main() {
	globalHistogramOnly();
	

}