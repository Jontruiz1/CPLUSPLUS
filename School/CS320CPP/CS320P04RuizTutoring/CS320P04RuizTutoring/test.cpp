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
		size_t verticies = g.getNumVertices();
		bitset<32> V = ~bitset<32>(1);
		W.resize(verticies, vector<int>(verticies));
		D.resize(verticies, bitset<32>(V));
		P.resize(verticies, bitset<32>(verticies));

		for (int i = 0; i < verticies; ++i) {
			for (int j = 0; j < verticies; ++j) {
				W[i][j] = g.getEdgeCost(i, j);
			}
		}
	}
	//unsigned int computeMinTourCost(int i);
	void travel(int n, int& minlength);
};


void Problem::travel(int n, int& minlength) {
	// 0 is like the nullset for the bitset

	int i, j, k;
	vector<bitset<32>> A;
	

	//
	for (i = 1; i < n; i++) {
		D[i][0] = W[i][0];
	}


	for (k = 1; k <= n - 1; k++) {

		// need to generate a subset of V - {v1}
		for (j = 1; j < k; ++j) {
			bitset<32> ono(i);
			if (ono.count() == k) {
				A.push_back(bitset<32>());
			}
		}

		// go through list of vector of subsets
		for (auto curr_set : A) {
			for (i = 1; i < n; ++i) {
				if (curr_set.test(i)) {
					continue;
				}
				for (j = 1; j < n; ++j) {
					unsigned int check_min = W[i][j] + D[j][curr_set.reset(j).to_ulong()];
					int j_min = j;

					if (check_min < D[i][curr_set.to_ulong()]) {
						D[i][curr_set.to_ulong()] = check_min;
						P[i][curr_set.to_ulong()] = j;
					}
				}
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
	int minlength;
	
	Graph tester;
	string fileName = "src1.txt";
	file.open(fileName);

	tester.read(file);
	tester.print();
	Problem mainP(tester);



	mainP.travel(tester.getNumVertices(), minlength);
	//unsigned int bestTourCost = mainP.computeMinTourCost(0, V.reset(0));

}