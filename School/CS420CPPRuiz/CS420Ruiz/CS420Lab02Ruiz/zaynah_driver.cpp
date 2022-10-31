#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <thread>
#include <algorithm>
#include <mutex>
using namespace std;

void fileToMemoryTransfer(char* fileName, char** data, size_t& numOfBytes);

int main(int argc, char** argv)
{
	const unsigned int THREAD_COUNT = thread::hardware_concurrency();
	//const unsigned int THREAD_COUNT = 1; // test with 1 thread
	char* buffer[1];
	size_t nbytes;
	vector<thread> workers(THREAD_COUNT); //vector of worker threads

	fileToMemoryTransfer(argv[1], buffer, nbytes); // read input
	const unsigned int CHAR_COUNT = 256;

	int chunk = nbytes / THREAD_COUNT;	// number of bytes divided amongst threads
	int extra = nbytes % THREAD_COUNT;	// leftover bytes
	int start = 0;		// start initialized as 0 because first thread goes through bytes in buffer starting at index 0 to bytes per thread minus 1 (since indexing starts at 0)
	int end = chunk;	// section that first thread goes through ends at number of bytes per thread (not included since indexing starts from 0)


	//// global histogram
	//vector<int> globalH(CHAR_COUNT, 0);

	//for (int t = 0; t < THREAD_COUNT; t++)
	//{
	//	if (t == THREAD_COUNT - 1)	// last thread processes any extra rows
	//		end += extra;

	//	workers.push_back(thread([t, &globalH](int start, int end, char** buffer)
	//		{
	//			for (unsigned int i = start; i < end; i++)
	//			{
	//				globalH.at((int)*buffer[i])++; // ONLY INCREMENTING FIRST CHAR, NOT CONTINUING TILL i = end
	//			}
	//		}, start, end, buffer)
	//	);
	//	// PROGRAM STOPPING, ABORT ERROR

	//	start = end;	// starting point in buffer for next thread is end of last thread
	//	end = start + chunk;	// end of next thread is the new start plus bytes per thread

	//}

	//for_each(workers.begin(), workers.end(), [](thread& t)
	//	{
	//		t.join();
	//	}
	//);

	//for (int i = 0; i < CHAR_COUNT; i++)
	//{
	//	cout << i << ": " << globalH.at(i) << endl;
	//}

	mutex m;
	// local histogram
	const unsigned int TOTAL_BUCKETS = CHAR_COUNT * THREAD_COUNT; // total "buckets" in vector containing all local histograms
	vector<unsigned int> h(TOTAL_BUCKETS, 0); // vector of local histograms created, all buckets initialized to 0

	start = 0;
	end = chunk;

	for (unsigned t = 0; t < THREAD_COUNT; t++)
	{
		if (t == THREAD_COUNT - 1) // last thread processes any extra rows
			end += extra;

		unsigned offset = CHAR_COUNT * t; // offset calculated so that the correct index is incremented depending on which thread is running, offset for first thread will be 0 (t = 0)

		workers.push_back(thread([t, &h](int start, int end, const char* buffer, int offset)
			{
				unsigned char curr;
				for (unsigned int i = start; i < end; i++)
				{
					// increment index of h at ascii value of the character at the position i + the offset calculated based on which thread it is
					curr = buffer[i];
					h.at((int)curr + offset)++; // STOPPING AFTER FIRST CHAR
				}
			}, start, end, *buffer, offset)
		);


		start = end;	// starting point in buffer for next thread is end of last thread
		end = start + chunk;	// end of next thread is the new start plus bytes per thread

	}


	for_each(workers.begin(), workers.end(), [](thread& t)
		{
			t.join();
		}
	);

	//for (int i = 0; i < CHAR_COUNT; i++)
	//{
	//	cout << i << ": " << h.at(t * CHAR_COUNT + i) << endl; // print local histogram after computing for that section
	//}
	return 0;
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