#include <iostream>
#include "graph.h"
#include <bitset>

class Problem {
private:
	vector<vector<int>> W;
	vector<bitset<32>> D;
	vector<bitset<32>> P;
public:
	Problem(Graph& g) {
		for (int i = 0; i < g.getNumVertices(); ++i) {
			for (int j = 0; j < g.getNumVertices(); ++j) {
				W[i][j] = g.getEdgeCost(i, j);
			}
		}
	}
	//unsigned int computeMinTourCost(int i);
	void travel(int n, bitset<32> S);
};


void Problem::travel(int n, bitset<32> S) {
	// 0 is like the nullset for the bitset

	int i, j, k;
	for (i = 2; i <= n; i++) {
		D[i][0] = W[i][0];
	}


	for (k = 1; k <= n - 2; k++) {
		for (;;) {
			for (;;) {

			}
		}
	}


}
//
//
//unsigned int Problem::computeMinTourCost(int i, bitset<32> S) {
//	bool found_at_least_one_vertex = false;
//	unsigned int aCost;
//	int best_vj;
//	int bestCost;
//	int best_j;
//
//	if (S.none()) return D[i][0];
//	if (D[i][0] >= 0) return D[i][S.to_ulong()];
//
//	bestCost = INT_MAX;
//	best_j = -1;
//	for (int j = 0; j < S.size(); j++) {
//		aCost = D[i][j] + computeMinTourCost(j, S.reset(j));
//		if (aCost < bestCost) {
//			found_at_least_one_vertex = true;
//			bestCost = aCost;
//			best_j = j;
//		}
//	}
//
//	if (found_at_least_one_vertex) {
//		D[best_j][S.to_ulong()] = bestCost;
//		P[i][S.to_ulong()] = best_j;
//	}
//	return bestCost;
//
//}
//
int main() {
	ifstream file;
	
	Graph tester;
	string fileName = "src1.txt";
	file.open(fileName);

	tester.read(file);
	tester.print();
	Problem mainP(tester);



	//mainP.travel(tester.getNumVertices(), );
	//unsigned int bestTourCost = mainP.computeMinTourCost(0, V.reset(0));

}