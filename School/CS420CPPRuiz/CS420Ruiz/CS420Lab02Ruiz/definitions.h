#ifndef DEFINITIONS_H
#define DEFINITIONS_H
#include <vector>
#include <mutex>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <thread>

using namespace std;

// reads the file into a data buffer
void fileToMemoryTransfer(char* fileName, char** data, size_t& numOfBytes);

// histogram design without using threads, for testing purposes
void sequentialHistogram(const unsigned MAX, const char* data, const size_t& bytes);

// global histogram design
void globalHistogram(const unsigned MAX, const unsigned THREAD_COUNT, const char* data, unsigned long long int* gH, const size_t& bytes, vector<thread>& workers);

// local histogram design
void localHistogram(const unsigned MAX, const unsigned THREAD_COUNT, const char* data, unsigned long long int* gH, const size_t& bytes, vector<thread>& workers);

#endif DEFINITIONS_H