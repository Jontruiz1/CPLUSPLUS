#pragma once
#include <fstream>
using namespace std;

void test_HT_unsigned_chaining(
	ofstream& htAnalysisFile,
	const unsigned NUM_OF_TABLES,
	const unsigned* tableSizes,
	const unsigned MAX_NUM_KEYS,
	const unsigned* arr_keys,
	const unsigned* arrSearchKeys,
	unsigned* initialTotalProbes,
	unsigned* resultSuccessContainsTotalProbes,
	unsigned* resultUnSuccessContainsTotalProbes,
	unsigned* successfulTotal,
	unsigned* unsuccessfulTotal
);

