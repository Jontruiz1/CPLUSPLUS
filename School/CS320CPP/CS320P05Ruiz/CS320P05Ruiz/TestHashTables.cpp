#include <iostream>
#include <fstream>
#include <string>
#include "UniformRandom.h"
#include "Test_HT_unsigned_Linear.h"
#include "Test_HT_unsigned_Quadratic.h"
#include "Test_HT_unsigned_Chaining.h"
#include "Test_HT_string_Linear.h" 
#include "Test_HT_string_Quadratic.h"
#include "Test_HT_string_Chaining.h"
using namespace std;

unsigned probes;     //communicate number of probes via global variable 

int main()
{
	const unsigned MAX_NUM_KEYS = 30000;
	const unsigned MAX_RANGE_OF_KEYS = 2 * MAX_NUM_KEYS;
	const unsigned NUM_OF_TABLES = 10;
	const unsigned TABLE_SIZE_LF10 = static_cast<unsigned>(MAX_NUM_KEYS / .1);
	const unsigned TABLE_SIZE_LF20 = static_cast<unsigned>(MAX_NUM_KEYS / .2);
	const unsigned TABLE_SIZE_LF30 = static_cast<unsigned>(MAX_NUM_KEYS / .3);
	const unsigned TABLE_SIZE_LF40 = static_cast<unsigned>(MAX_NUM_KEYS / .4);
	const unsigned TABLE_SIZE_LF50 = static_cast<unsigned>(MAX_NUM_KEYS / .5);
	const unsigned TABLE_SIZE_LF60 = static_cast<unsigned>(MAX_NUM_KEYS / .6);
	const unsigned TABLE_SIZE_LF70 = static_cast<unsigned>(MAX_NUM_KEYS / .7);
	const unsigned TABLE_SIZE_LF80 = static_cast<unsigned>(MAX_NUM_KEYS / .8);
	const unsigned TABLE_SIZE_LF90 = static_cast<unsigned>(MAX_NUM_KEYS / .9);
	const unsigned tableSizes[] = { 0, TABLE_SIZE_LF10, TABLE_SIZE_LF20, TABLE_SIZE_LF30, TABLE_SIZE_LF40,
		TABLE_SIZE_LF50, TABLE_SIZE_LF60, TABLE_SIZE_LF70, TABLE_SIZE_LF80, TABLE_SIZE_LF90 };
	////Example: MAX_NUM_KEYS = 10000u;
	//// TABLE_SIZE_LF10 = 100000;// 10% load factor
	//// TABLE_SIZE_LF20 = 50000; // 20% load factor
	//// TABLE_SIZE_LF30 = 33334; // 30% load factor
	//// TABLE_SIZE_LF40 = 25000; // 40% load factor
	//// TABLE_SIZE_LF50 = 20000; // 50% load factor
	//// TABLE_SIZE_LF60 = 16667; // 60% load factor
	//// TABLE_SIZE_LF70 = 14286; // 70% load factor
	//// TABLE_SIZE_LF80 = 12500; // 80% load factor
	//// TABLE_SIZE_LF90 = 11111; // 90% load factor

	//Generate keys
	UniformRandom randNum(2001);  //seed with specific number so simulations are same.  
	UniformRandom randNum_j(217); // 
	UniformRandom randNum_k(3); // 

	unsigned keys_universe[MAX_RANGE_OF_KEYS] = { 0 };
	unsigned arr_keys[MAX_NUM_KEYS] = { 0 };
	unsigned arrSearchKeys[MAX_NUM_KEYS] = { 0 };
	for (unsigned i = 0; i < MAX_RANGE_OF_KEYS; i++) {
		keys_universe[i] = i + 1;
	}

	// ofstream constructor opens a file for storing analysis of probing statistics
	ofstream htAnalysisFile("HashTableAnalysis.txt", ios::out);
	if (!htAnalysisFile) { // overload ! ios function returns true if problems opening file
		cerr << "HashTableAnalysis.txt could not be created or overwritten." << endl;
		exit(1);
	}

	cout << "Generating unsigned keys between 0 and " << MAX_RANGE_OF_KEYS
		<< " to be initially inserted in HashTable<unsigned> objects." << endl;
	//set up insert keys by randomizing a range of keys from 0 to MAX_RANGE_OF_KEYS-1
	for (unsigned i = 0; i < MAX_RANGE_OF_KEYS; i++) {
		unsigned j = randNum_j.nextInt(0, MAX_RANGE_OF_KEYS - 1);  //Random num from a closed interval [0..MAX_RANGE_OF_KEYS-1]
		unsigned k = randNum_k.nextInt(0, MAX_RANGE_OF_KEYS - 1);
		unsigned temp = keys_universe[j];
		keys_universe[j] = keys_universe[k];
		keys_universe[k] = temp;
	}
	//grab the first MAX_NUM_KEYS keys from jumbled universe of keys
	for (unsigned i = 0; i < MAX_NUM_KEYS; i++) {
		arr_keys[i] = keys_universe[i];
	}
	cout << "Generating keys between 0 and " << MAX_RANGE_OF_KEYS
		<< " to analyze searching HashTable<unsigned> objects." << endl;
	/* mix up keys_universe again */
	for (unsigned i = 0; i < MAX_RANGE_OF_KEYS; i++) {
		unsigned j = randNum_j.nextInt(0, MAX_RANGE_OF_KEYS - 1);  //This is a closed interval not a right-side open
		unsigned k = randNum_k.nextInt(0, MAX_RANGE_OF_KEYS - 1);
		unsigned temp = keys_universe[j];
		keys_universe[j] = keys_universe[k];
		keys_universe[k] = temp;
	}
	/*Grab first MAX_NUM_KEYS for re-jumbled universe for testing searches
	with some new keys for unsuccessful searches */
	for (unsigned i = 0; i < MAX_NUM_KEYS; i++) {
		arrSearchKeys[i] = keys_universe[i];
	}
	unsigned initialTotalProbes[NUM_OF_TABLES] = { 0 };
	unsigned resultSuccessContainsTotalProbes[NUM_OF_TABLES] = { 0 };
	unsigned resultUnSuccessContainsTotalProbes[NUM_OF_TABLES] = { 0 };
	unsigned successfulTotal[NUM_OF_TABLES] = { 0 };
	unsigned unsuccessfulTotal[NUM_OF_TABLES] = { 0 };

	//***********************************Linear Probing using unsigned keys***********************		
	test_HT_unsigned_linear(htAnalysisFile, NUM_OF_TABLES, tableSizes,
		MAX_NUM_KEYS, arr_keys, arrSearchKeys,
		initialTotalProbes,
		resultSuccessContainsTotalProbes,
		resultUnSuccessContainsTotalProbes,
		successfulTotal,
		unsuccessfulTotal);

	//***********************************Quadratic Probing using unsigned keys***********************

	test_HT_unsigned_quadratic(htAnalysisFile, NUM_OF_TABLES, tableSizes,
		MAX_NUM_KEYS, arr_keys, arrSearchKeys,
		initialTotalProbes,
		resultSuccessContainsTotalProbes,
		resultUnSuccessContainsTotalProbes,
		successfulTotal,
		unsuccessfulTotal);

	//***********************************Hash Table with Chaining Probing Tests***********************

	test_HT_unsigned_chaining(htAnalysisFile, NUM_OF_TABLES, tableSizes,
		MAX_NUM_KEYS, arr_keys, arrSearchKeys,
		initialTotalProbes,
		resultSuccessContainsTotalProbes,
		resultUnSuccessContainsTotalProbes,
		successfulTotal,
		unsuccessfulTotal);

	//********************* Test strings******************
	const unsigned MAX_RANGE_OF_WORD_KEYS = 2 * MAX_NUM_KEYS;
	string wordKeys_universe[MAX_RANGE_OF_WORD_KEYS] = { string("") };
	string arr_wordkeys[MAX_NUM_KEYS] = { string("") };
	string arrSearchWordKeys[MAX_NUM_KEYS] = { string("") };

	//Generate string keys

	ifstream dictionaryIn;
	dictionaryIn.open("dictionary.txt");
	if (!dictionaryIn)
	{
		cerr << "Cannot open 'dictionary.txt'" << endl;
		htAnalysisFile.close();
		exit(1);
	}

	unsigned numWords = 0;
	for (unsigned i = 0; i < MAX_RANGE_OF_WORD_KEYS && dictionaryIn; i++) {
		string word;
		if (dictionaryIn >> word) {
			wordKeys_universe[i] = word;
			numWords++;
		}
	}
	dictionaryIn.close();
	cout << "Generating unsigned keys between 0 and " << MAX_RANGE_OF_KEYS
		<< " to be initially inserted in HashTable<string> objects." << endl;
	//set up insert keys by randomizing a range of keys from 0 to MAX_RANGE_OF_KEYS-1
	for (unsigned i = 0; i < MAX_RANGE_OF_WORD_KEYS; i++) {
		unsigned j = randNum_j.nextInt(0, MAX_RANGE_OF_WORD_KEYS - 1);  //Random num from a closed interval [0..MAX_RANGE_OF_KEYS-1]
		unsigned k = randNum_k.nextInt(0, MAX_RANGE_OF_WORD_KEYS - 1);
		string temp = wordKeys_universe[j];
		wordKeys_universe[j] = wordKeys_universe[k];
		wordKeys_universe[k] = temp;
	}
	//grab the first MAX_NUM_KEYS keys from jumbled universe of keys
	for (unsigned i = 0; i < MAX_NUM_KEYS; i++) {
		arr_wordkeys[i] = wordKeys_universe[i];
	}

	cout << "Generating keys between 0 and " << MAX_RANGE_OF_KEYS
		<< " to analyze searching HashTable<string> objects." << endl;
	/* mix up wordKeys_universe again */
	for (unsigned i = 0; i < MAX_RANGE_OF_WORD_KEYS; i++) {
		unsigned j = randNum_j.nextInt(0, MAX_RANGE_OF_WORD_KEYS - 1);  //This is a closed interval not a right-side open
		unsigned k = randNum_k.nextInt(0, MAX_RANGE_OF_WORD_KEYS - 1);
		string temp = wordKeys_universe[j];
		wordKeys_universe[j] = wordKeys_universe[k];
		wordKeys_universe[k] = temp;
	}
	/*Grab first MAX_NUM_KEYS for re-jumbled universe for testing searches
	with some new keys for unsuccessful searches */
	for (unsigned i = 0; i < MAX_NUM_KEYS; i++) {
		arrSearchWordKeys[i] = wordKeys_universe[i];
	}
	//********Test HashTable<string> Linear Probing using above string keys from dictionary*******
	test_HT_string_linear(htAnalysisFile, NUM_OF_TABLES, tableSizes,
		MAX_NUM_KEYS, arr_wordkeys, arrSearchWordKeys,
		initialTotalProbes,
		resultSuccessContainsTotalProbes,
		resultUnSuccessContainsTotalProbes,
		successfulTotal,
		unsuccessfulTotal);

	//********Test HashTable<string> Quadratic Probing using above string keys from dictionary*******
	test_HT_string_quadratic(htAnalysisFile, NUM_OF_TABLES, tableSizes,
		MAX_NUM_KEYS, arr_wordkeys, arrSearchWordKeys,
		initialTotalProbes,
		resultSuccessContainsTotalProbes,
		resultUnSuccessContainsTotalProbes,
		successfulTotal,
		unsuccessfulTotal);

	//********Test HashTable<string> Quadratic Probing using above string keys from dictionary*******
	test_HT_string_chaining(htAnalysisFile, NUM_OF_TABLES, tableSizes,
		MAX_NUM_KEYS, arr_wordkeys, arrSearchWordKeys,
		initialTotalProbes,
		resultSuccessContainsTotalProbes,
		resultUnSuccessContainsTotalProbes,
		successfulTotal,
		unsuccessfulTotal);
	cout << "Finished testing " << endl;

	htAnalysisFile.close();
}
