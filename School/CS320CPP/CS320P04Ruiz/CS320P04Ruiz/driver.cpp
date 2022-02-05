#include <iostream>
#include <fstream>
#include <bitset>
#include <string>
#include <vector>
#include <assert.h>
#include <sstream>

using namespace std;

void travel(int n, vector<vector<int>>& M, vector<vector<bitset<32>>>& D, vector<vector<bitset<32>>>& P,unsigned& minlength) {
    int i, k, j;
    bool a_moved = false;
    bitset<32> U(0);
    vector<bitset<32>> V;

    for (i = 1; i < n; i++) {
        D[i][0] = M[i][0];
    }

    // k = size of subsets
    for (k = 1; k <= n-1; k++) {
        //get all the subsets A of V without v1 that have k vertices
       
        //I don't ever reset the vector here, so, to be completely honest,
        //I don't know why it works.
        //Didn't have time to trace it
        for (i = 1; i < pow(2, n); i++) {
            bitset<32> tmp(i);
            if (tmp.count() == k && !tmp.test(0)) {
                V.push_back(tmp);
            }
        }

        //go through the list of subsets
        for (auto s = V.begin(); s != V.end()-1; s++) {
            bitset<32> A = *s;
            auto aVal = A.to_ulong();

            for (i = 1; i < n; i++) {
                //{i} is in the current subset? Go to the next set, make a temp variable to check for this
                if(A.test(i)) {
                    A = *(++s);
                    a_moved = true;
                }
                for (j = 1; j < n; j++) {
                    //don't want the weight to be 0 or to check a node that doesn't exist
                    if (i == j || M[i][j] == INT_MAX) continue;
                    bitset<32> a_and_not_j = A;
                    a_and_not_j.flip(j);

                    if (D[i][A.to_ulong()].to_ulong() > D[j][a_and_not_j.to_ulong()].to_ulong() + M[i][j]) {
                        D[i][A.to_ulong()] = (D[j][a_and_not_j.to_ulong()].to_ulong() + M[i][j]);
                        P[i][A.to_ulong()] = j;
                    }
                }
                // if we moved to the next subset, we need to move back and reset the temp var
                if (a_moved) {
                    A = *(--s);
                    a_moved = false;
                }
            }
        }
    }
    //get the universal set, so all the bits up to n need to flip besides the 1 bit;
    for (i = 1; i < n; i++) {
        U.flip(i);
    }
    //find minimum cost
    bitset<32> v_no_one = U; //V - {v1};
    for (j = 1; j < n; j++) {
        bitset<32> noJ = U.flip(j); //take the j out so now U doesn't incldue {v1, vj}
        if (D[0][v_no_one.to_ulong()].to_ulong() > M[0][j] + D[j][noJ.to_ulong()].to_ulong()) {

            D[0][v_no_one.to_ulong()] = M[0][j] + D[j][noJ.to_ulong()].to_ulong();
            P[0][v_no_one.to_ulong()] = j;
            minlength = D[0][v_no_one.to_ulong()].to_ulong();
        }
        U.flip(j); //put the j back in U
    }
}

void printMinCostTour(unsigned n, vector<vector<bitset<32>>>& P, bitset<32> V, vector<pair<int, string>> names) {
    unsigned v = 0; //starting vertex
    bitset<32> A = V.reset(v);
    cout << "<";
    cout << get<1>(names[v]);

    while (A.to_ulong() != 0) {
        cout << ",";
        v = P[v][A.to_ulong()].to_ulong();
        cout << get<1>(names[v]);
        A = A.reset(v);
    }
    cout << ">";


}

int main() {
    string line, name, word;
    int id, inId, out_edge, n = 0;
    string read_file;
    ifstream infile;
    pair<int, int> temp;

    vector<pair<int, string>> names;
    vector<pair<int, int>> weights;

    vector<vector<int>> M;
    vector<vector<bitset<32>>>D;
    vector<vector<bitset<32>>>P;

    bitset<32> U(0);
    unsigned minlength;
    

    cout << "Enter a filename(including extension): ";
    cin >> read_file;

    infile.open("Input\\" + read_file);
    if (infile) {
        while (getline(infile, line)) {
            istringstream ss(line);

            ss >> id >> name;
            while (ss >> inId >> out_edge) {
                weights.push_back(make_pair(inId, out_edge));
            }

            names.push_back(make_pair(id, name));
            n++;

        }
        M.resize(n, vector<int>(n));
    } else {
        cout << "File could not open";
    }

    int curr = 1;
    for (auto j = weights.begin(); j != weights.end(); j++) {

        if (curr > n) {
            curr = 1;
        }
        if (get<0>(*j) != curr) {
            j = weights.insert(j, make_pair(curr, INT_MAX));
        }
        curr++;
    }

    curr = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            M[i][j] = get<1>(weights[curr]);
            curr++;
        }
    }

    //initializes each individual bitset in D
    D.resize(M.size());
    P.resize(M.size());
    for (int i = 0; i < M.size(); i++) {
        D[i].resize(pow(2, M.size()));
        P[i].resize(pow(2, M.size()));
        U.flip(i);
    }
    for (int i = 0; i < D.size(); i++) {
        for (int j = 0; j < D[i].size(); j++) {
            D[i][j] = INT_MAX;
            P[i][j] = INT_MAX;
        }
    }

    travel(M.size(), M, D, P, minlength);

    if (minlength >= INT_MAX) {
        cout << "No Hamiltonian Circuit" << endl;
        exit(0);
    }
    else {
        cout << endl <<"**** Output according to " << read_file << "****" <<endl;
        cout << "Optimal Tour Cost = [" << minlength << ", ";
        printMinCostTour(n, P, U, names);
        cout << "]" << endl;
    }
    
    
    
    
    
}
