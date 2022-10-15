#include <iostream>
#include <fstream>
#include <thread>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

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

/* binary vs text files 
* read(ch)
* map each value in an array to the value in the file
* increment the value in the array when you find that value in the file
* 
*/


int main() {
	//thread::hardware_concurrency();
	
	char fileName[] = "File1.txt";
	size_t size;

	fileToMemoryTransfer(fileName, buffer, size);
	char* data = (char*)malloc(size * sizeof(char));

	
}