#include <iostream>
#include "graph.h"
#include <bitset>

class Problem {
private:
	bitset<32> S;
	vector<vector<int>> D;
	vector<vector<unsigned int>> P;

	unsigned int gCost(unsigned int i, bitset<32> S, Graph& g) {
		unsigned int nVertices = g.getNumVertices();
		bool found_at_least_one_vertex = false;
		unsigned int costThru_j;
		unsigned int best_j = -1;
		unsigned int aCost;
		bitset<32> min_S;

		if (S.none()) return D[i][0];
		if (D[i][0] >= 0) return D[i][S.to_ulong()];

		unsigned int bestCost = INT_MAX;
		
		for (unsigned j = 1; j < nVertices; j++) {
			if (S.test(j)) {
				bitset<32> S_Temp = S;
				aCost = D[i][j] + gCost(j, S_Temp.reset(j), g);
				if (aCost < bestCost) {
					found_at_least_one_vertex = true;
					bestCost = aCost;
					best_j = j;
				}
				if (found_at_least_one_vertex) {
					D[best_j][S.to_ulong()] = bestCost;
					P[i][S.to_ulong()] = best_j;
				}
			}
		}

		

		return bestCost;
	}
public:
	
	/*tuple<int, vector<string>>*/unsigned int solve(Graph& g) {
		vector<int> v_temp;
		vector<unsigned> v_pathTemp;
		unsigned int nVertices = g.getNumVertices();
		unsigned int minCost = 0;
		
		for (unsigned int i = 0; i < nVertices; i++) {
			v_temp.resize(static_cast<int>(pow(2, nVertices)));
			v_temp.assign(v_temp.size(), -1);
			D.push_back(v_temp);
		}
		for (size_t i = 0; i < nVertices; i++) {
			S.set(i);
		}
		minCost = gCost(0, S.reset(0), g);

		return minCost;

	}
};


//void Problem::travel(int n, int& minlength) {
//	// 0 is like the nullset for the bitset
//
//	int i, j, k;
//	vector<bitset<32>> A;
//	
//
//	//
//	for (i = 1; i < n; i++) {
//		D[i][0] = W[i][0];
//	}
//
//
//	for (k = 1; k <= n - 1; k++) {
//
//		// need to generate a subset of V - {v1}
//		for (j = 1; j < k; ++j) {
//			bitset<32> ono(i);
//			if (ono.count() == k) {
//				A.push_back(bitset<32>());
//			}
//		}
//
//		// go through list of vector of subsets
//		for (auto curr_set : A) {
//			for (i = 1; i < n; ++i) {
//				if (curr_set.test(i)) {
//					continue;
//				}
//				for (j = 1; j < n; ++j) {
//					unsigned int check_min = W[i][j] + D[j][curr_set.reset(j).to_ulong()];
//					int j_min = j;
//
//					if (check_min < D[i][curr_set.to_ulong()]) {
//						D[i][curr_set.to_ulong()] = check_min;
//						P[i][curr_set.to_ulong()] = j;
//					}
//				}
//			}
//		}
//	}
//
//
//}

int main() {
	ifstream file;
	int minlength;
	
	Graph tester;
	string fileName = "src1.txt";
	file.open(fileName);

	tester.read(file);
	tester.print();
	Problem mainP;



	cout << mainP.solve(tester);
	//unsigned int bestTourCost = mainP.computeMinTourCost(0, V.reset(0));

}