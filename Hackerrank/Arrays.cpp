#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int n, q, k, i, j;
    cin >> n >> q;

    vector<vector<int>> queries(n);
    
    for(int x = 0; x < n; ++x){
        cin >> k;
        queries[x].resize(k);
        for(int y = 0; y < k; ++y){
            cin >> queries[x][y];
        }
    }

    for(int z = 0; z < q; ++z){
        cin >> i >> j;
        cout << queries[i][j] << endl;
    }
}