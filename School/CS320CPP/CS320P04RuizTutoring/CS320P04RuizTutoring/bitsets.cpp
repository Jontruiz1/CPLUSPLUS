#include <iostream>
#include <bitset>
#include <vector>

using namespace std;

int main() {
	int k, i, j;
	vector<bitset<32>> D;
	vector<bitset<32>> P;
	int n = 32;



	// outer for loop
	for (k = 1; k <= n; ++k) {
		vector< bitset<32>> sets;
		for (i = 0; i < n; i++) {
			if (bitset<32>(i).size() == k) sets.flip(i);
		}
		// need to get all the subsets of the universal set containing k verticies

	}

	
}