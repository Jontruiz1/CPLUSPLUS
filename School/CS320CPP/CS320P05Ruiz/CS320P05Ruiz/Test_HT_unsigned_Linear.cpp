#include <vector>
#include <iostream>
#include <fstream>
#include "LinearProbing.h"

void test_HT_unsigned_linear(
	ofstream& htAnalysisFile,
	const unsigned NUM_OF_TABLES,
	const unsigned* tableSizes,
	const unsigned MAX_NUM_KEYS,
	const unsigned* arr_keys,
	const unsigned* arrSearchKeys,
	unsigned* resultTotalProbes,
	unsigned* resultSuccessContainsTotalProbes,
	unsigned* resultUnSuccessContainsTotalProbes,
	unsigned* successfulTotal,
	unsigned* unsuccessfulTotal
)

////***********************************Linear Probing using unsigned keys***********************
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
	vector<HashTableLinear<unsigned>> hl{
		HashTableLinear<unsigned>(),				 //Not used.
		HashTableLinear<unsigned>(TABLE_SIZE_1),  //MAX_NUM_KEYS/.1 gets first prime greater than TABLE_SIZE_LF10
		HashTableLinear<unsigned>(TABLE_SIZE_2),  //MAX_NUM_KEYS/.2
		HashTableLinear<unsigned>(TABLE_SIZE_3),  //MAX_NUM_KEYS/.3
		HashTableLinear<unsigned>(TABLE_SIZE_4),  //MAX_NUM_KEYS/.4
		HashTableLinear<unsigned>(TABLE_SIZE_5),   //MAX_NUM_KEYS/.5
		HashTableLinear<unsigned>(TABLE_SIZE_6),  //MAX_NUM_KEYS/.6
		HashTableLinear<unsigned>(TABLE_SIZE_7),  //MAX_NUM_KEYS/.7
		HashTableLinear<unsigned>(TABLE_SIZE_8),  //MAX_NUM_KEYS/.8
		HashTableLinear<unsigned>(TABLE_SIZE_9)   //MAX_NUM_KEYS/.9
	};


	////Test Linear Probing with vector of HashTableLinear<unsigned>
	cout << "****Starting analysis of HashTable<unsigned> using Linear Probing ****" << endl;
	htAnalysisFile << "****Starting analysis of HashTable<unsigned> using Linear Probing ****" << endl;
	unsigned tableNum;
	for (tableNum = 1; tableNum < NUM_OF_TABLES; tableNum++) {
		probes = 0;
		for (unsigned i = 0; i < MAX_NUM_KEYS; i++) {
			hl[tableNum].insert(arr_keys[i]);
			resultTotalProbes[tableNum] += probes;
		}
	}

	for (tableNum = 1; tableNum < NUM_OF_TABLES; tableNum++) {
		htAnalysisFile << "Table" << tableNum << " has " << hl[tableNum].getNumBuckets() << " buckets."
			<< " load factor =  " << static_cast<double>(MAX_NUM_KEYS) / hl[tableNum].getNumBuckets() << endl;
	}

	htAnalysisFile << "Linear Probing Initial Insertion Results:\n";
	for (unsigned i = 1; i < NUM_OF_TABLES; i++) {
		htAnalysisFile << i << "\t\t";
	}
	htAnalysisFile << endl;
	for (unsigned i = 1; i < NUM_OF_TABLES; i++) {
		htAnalysisFile << resultTotalProbes[i] << "\t";
	}
	htAnalysisFile << endl;
	for (unsigned i = 1; i < NUM_OF_TABLES; i++) {
		htAnalysisFile << resultTotalProbes[i] / static_cast<double>(MAX_NUM_KEYS) << "\t";
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

	htAnalysisFile << "Linear Probing Successful Contains Results:\n";
	for (unsigned i = 1; i < NUM_OF_TABLES; i++) {
		htAnalysisFile << i << "\t\t";
	}
	htAnalysisFile << endl;
	for (unsigned i = 1; i < NUM_OF_TABLES; i++) {
		htAnalysisFile << resultSuccessContainsTotalProbes[i] << "\t";
	}
	htAnalysisFile << endl;
	htAnalysisFile << "Average Successful Contains: \n";
	for (unsigned i = 1; i < NUM_OF_TABLES; i++) {
		htAnalysisFile << resultSuccessContainsTotalProbes[i] / static_cast<double>(successfulTotal[i]) << "\t";
	}
	htAnalysisFile << endl;

	htAnalysisFile << "Linear Probing Unsuccessful Contains Results:\n";
	for (unsigned i = 1; i < NUM_OF_TABLES; i++) {
		htAnalysisFile << i << "\t\t";
	}
	htAnalysisFile << endl;
	for (unsigned i = 1; i < NUM_OF_TABLES; i++) {
		htAnalysisFile << resultUnSuccessContainsTotalProbes[i] << "\t";
	}
	htAnalysisFile << endl;
	htAnalysisFile << "Average Unsuccessful Contains: \n";
	for (unsigned i = 1; i < NUM_OF_TABLES; i++) {
		htAnalysisFile << resultUnSuccessContainsTotalProbes[i] / static_cast<double>(unsuccessfulTotal[i]) << "\t";
	}
	htAnalysisFile << endl;
	cout << "****Finished analysis of HashTable<unsigned> using Linear Probing ****" << endl;
	htAnalysisFile << "****Finished analysis of HashTable<unsigned> using Linear Probing ****" << endl;
	htAnalysisFile << endl;
}