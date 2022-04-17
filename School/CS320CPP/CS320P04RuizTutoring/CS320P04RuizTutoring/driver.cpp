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
		unsigned int aCost;

		bitset<32> min_S;
		if (S.none()) return g.getEdgeCost(i, 0);
		if (D[i][S.to_ulong()] >= 0) return D[i][S.to_ulong()];

		unsigned int bestCost = INT_MAX;
		unsigned int min_j = -1;

		for (unsigned j = 1; j < nVertices; j++) {
			if (S.test(j)) {
				bitset<32> S_Temp = S;
				S_Temp.reset(j);
				aCost = g.getEdgeCost(i, j) + gCost(j, S_Temp, g);
				if (aCost < bestCost) {
					found_at_least_one_vertex = true;
					bestCost = aCost;
					min_j = j;
				}
			}
		}

		if (found_at_least_one_vertex) {
			D[min_j][S.to_ulong()] = bestCost;
			P[i][S.to_ulong()] = min_j;
		}

		return bestCost;
	}
public:
	
	tuple<int, vector<string>> solve(Graph& g) {
		vector<int> v_temp;
		vector<unsigned> v_pathTemp;
		vector<string> names;
		unsigned int nVertices = g.getNumVertices();
		unsigned int minCost = 0;

		for (unsigned int i = 0; i < nVertices; i++) {
			v_temp.resize(static_cast<int>(pow(2, nVertices)));
			v_temp.assign(v_temp.size(), -1);
			v_pathTemp.resize(static_cast<int>(pow(2, nVertices)));
			v_pathTemp.assign(v_temp.size(), -1);

			D.push_back(v_temp);
			P.push_back(v_pathTemp);
		}

		for (size_t i = 0; i < nVertices; i++) {
			S.set(i);
		}
		minCost = gCost(0, S.reset(0), g);

		// S = 1110
		// while S is not null
		// get the new i, ie. current node that we're at
		// store the name of that vertex somewhere
		// get rid of the i bit in S
		// we don't need to revist that node
		unsigned int i = 0;
		names.push_back(g.getVertexName(i));
		


		return { minCost, names };
	}

};

int main() {
	ifstream file;
	int minlength;
	tuple<int, vector<string>> result;
	vector<string> names;
	
	Graph tester;
	string fileName = "src1.txt";
	file.open(fileName);

	tester.read(file);
	tester.print();
	Problem mainP;

	result = mainP.solve(tester);
	minlength = get<0>(result);
	names = get<1>(result);

	cout << "[" << minlength << ",<";
	for (int i = 0; i < names.size(); ++i) {
		cout << names[i] << ((i != names.size()-1) ? "," : ">]");
	}
}