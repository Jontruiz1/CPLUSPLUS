#ifndef DEFINITIONS_H
#define DEFINITIONS_H
#include <vector>
#include <mutex>
#include <algorithm>
#include <iostream>
#include <fstream>

using namespace std;

void fileToMemoryTransfer(char* fileName, char** data, size_t& numOfBytes);
void sequentialHistogram(const unsigned MAX, const char* data, const size_t& bytes);
void globalHistogram(const unsigned MAX, const unsigned THREAD_COUNT, const char* data, unsigned int* gH, const size_t& bytes, vector<thread>& workers);
void localHistogram(const unsigned MAX, const unsigned THREAD_COUNT, const char* data, unsigned int* gH, const size_t& bytes, vector<thread>& workers);

#endif DEFINITIONS_H