#pragma once
#include <fstream>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>  
#include "QuadraticProbing.h"
#include "UniformRandom.h" 
using namespace std;

//****************Testing HashTable<string> with Quadratic Probing****************

void test_HT_string_quadratic(
	ofstream& htAnalysisFile,
	const unsigned NUM_OF_TABLES,
	const unsigned* tableSizes,
	const unsigned MAX_NUM_KEYS,
	const string* arr_keys,
	const string* arrSearchKeys,
	unsigned* initialTotalProbes,
	unsigned* resultSuccessContainsTotalProbes,
	unsigned* resultUnSuccessContainsTotalProbes,
	unsigned* successfulTotal,
	unsigned* unsuccessfulTotal
)
//****************Testing HashTable with Chaining using string keys*****************
{
	
	const unsigned TABLE_SIZE_1 = tableSizes[1];
	const unsigned TABLE_SIZE_2 = tableSizes[2];
	const unsigned TABLE_SIZE_3 = tableSizes[3];
	const unsigned TABLE_SIZE_4 = tableSizes[4];
	const unsigned TABLE_SIZE_5 = tableSizes[5];
	const unsigned TABLE_SIZE_6 = tableSizes[6];
	const unsigned TABLE_SIZE_7 = tableSizes[7];
	const unsigned TABLE_SIZE_8 = tableSizes[8];
	const unsigned TABLE_SIZE_9 = tableSizes[9];
	vector<HashTableQuad<string>> hl{
		HashTableQuad<string>(),			  //Not used.
		HashTableQuad<string>(TABLE_SIZE_1),  //MAX_NUM_KEYS/.1 gets first prime greater than TABLE_SIZE_LF10
		HashTableQuad<string>(TABLE_SIZE_2),  //MAX_NUM_KEYS/.2
		HashTableQuad<string>(TABLE_SIZE_3),  //MAX_NUM_KEYS/.3
		HashTableQuad<string>(TABLE_SIZE_4),  //MAX_NUM_KEYS/.4
		HashTableQuad<string>(TABLE_SIZE_5),   //MAX_NUM_KEYS/.5
		HashTableQuad<string>(TABLE_SIZE_6),  //MAX_NUM_KEYS/.6
		HashTableQuad<string>(TABLE_SIZE_7),  //MAX_NUM_KEYS/.7
		HashTableQuad<string>(TABLE_SIZE_8),  //MAX_NUM_KEYS/.8
		HashTableQuad<string>(TABLE_SIZE_9)   //MAX_NUM_KEYS/.9
	};

	//Test Chaining Probing with vector of HashTableChaining<unsigned>
	cout << "****Starting analysis of HashTable<string> using Quadratic Probing****" << endl;
	htAnalysisFile << "****Starting analysis of HashTable<string> using Quadratic Probing****" << endl;
	for (unsigned i = 0; i < NUM_OF_TABLES; i++)
		initialTotalProbes[i] = 0;
	unsigned tableNum;
	for (tableNum = 1; tableNum < NUM_OF_TABLES; tableNum++) {
		probes = 0;
		for (unsigned i = 0; i < MAX_NUM_KEYS; i++) {
			hl[tableNum].insert(arr_keys[i]);
			initialTotalProbes[tableNum] += probes;
		}
	}

	for (tableNum = 1; tableNum < NUM_OF_TABLES; tableNum++) {
		htAnalysisFile << "Table" << tableNum << " has " << hl[tableNum].getNumBuckets() << " buckets."
			<< " load factor =  " << static_cast<double>(MAX_NUM_KEYS) / hl[tableNum].getNumBuckets() << endl;
	}

	htAnalysisFile << "HT<string> Quadratic Probing Initial Insertion of strings:\n";
	for (unsigned i = 1; i < NUM_OF_TABLES; i++) {
		htAnalysisFile << i << "\t\t";
	}
	htAnalysisFile << endl;
	for (unsigned i = 1; i < NUM_OF_TABLES; i++) {
		htAnalysisFile << initialTotalProbes[i] << "\t";
	}
	htAnalysisFile << endl;
	for (unsigned i = 1; i < NUM_OF_TABLES; i++) {
		htAnalysisFile << initialTotalProbes[i] / static_cast<double>(MAX_NUM_KEYS) << "\t";
	}
	htAnalysisFile << endl;

	//Count probes for successes and unsuccessful searchs of search keys 

	for (unsigned i = 0; i < NUM_OF_TABLES; i++) {
		resultSuccessContainsTotalProbes[i] = 0;
		resultUnSuccessContainsTotalProbes[i] = 0;
		successfulTotal[i] = 0;
		unsuccessfulTotal[i] = 0;
	}

	for (tableNum = 1; tableNum < NUM_OF_TABLES; tableNum++) {
		probes = 0;
		for (unsigned i = 0; i < MAX_NUM_KEYS; i++) {
			if (hl[tableNum].contains(arrSearchKeys[i])) {
				resultSuccessContainsTotalProbes[tableNum] += probes;
				successfulTotal[tableNum]++;
			}
			else {
				resultUnSuccessContainsTotalProbes[tableNum] += probes;
				unsuccessfulTotal[tableNum]++;
			}
		}
	}
	htAnalysisFile << "HT<string> Quadratic Probing Successful 'Contains' Probes Totals:\n";
	for (unsigned i = 1; i < NUM_OF_TABLES; i++) {
		htAnalysisFile << i << "\t\t";
	}
	htAnalysisFile << endl;
	for (unsigned i = 1; i < NUM_OF_TABLES; i++) {
		htAnalysisFile << resultSuccessContainsTotalProbes[i] << "\t";
	}
	htAnalysisFile << endl;
	htAnalysisFile << "HT<string> Quadratic Probing Average Successful 'Contains': \n";
	for (unsigned i = 1; i < NUM_OF_TABLES; i++) {
		htAnalysisFile << resultSuccessContainsTotalProbes[i] / static_cast<double>(successfulTotal[i]) << "\t";
	}
	htAnalysisFile << endl;
	htAnalysisFile << "HT<string> Quadratic Probing Unsuccessful 'Contains' Probe Totals: \n";
	for (unsigned i = 1; i < NUM_OF_TABLES; i++) {
		htAnalysisFile << i << "\t\t";
	}
	htAnalysisFile << endl;
	for (unsigned i = 1; i < NUM_OF_TABLES; i++) {
		htAnalysisFile << resultUnSuccessContainsTotalProbes[i] << "\t";
	}
	htAnalysisFile << endl;
	htAnalysisFile << "HT<string> Quadratic Probing Average Unsuccessful Contains: \n";
	for (unsigned i = 1; i < NUM_OF_TABLES; i++) {
		htAnalysisFile << resultUnSuccessContainsTotalProbes[i] / static_cast<double>(unsuccessfulTotal[i]) << "\t";
	}
	htAnalysisFile << endl;
	htAnalysisFile << "****Finished analysis of HashTable<string> using Quadratic Probing****" << endl;
	cout << "****Finished analysis of HashTable<string> using Quadratic Probing****" << endl;
	htAnalysisFile << endl;
	
}

