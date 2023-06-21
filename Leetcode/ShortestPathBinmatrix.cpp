#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution{
    public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid){
        vector<pair<int, int>> open = {{0, 0}};
        vector<pair<int, int>> closed;
        int currpath = 0;
        
        while(!open.empty()){
            
            pair<int, int> curr = open.front();
            int row = curr.first, col = curr.second;
            if(grid[row][col]){
                return -1;
            }
            else

            closed.push_back(open.front());
            open.erase(open.begin());
        }
        return -1;

        
    }
};

int main(){
    cout << "Test 1, should be -1" << endl;
    vector<vector<int>> grid1 = {{1, 0, 0}, {1, 1, 0}, {1, 1, 0}};
    Solution tester;
    cout << tester.shortestPathBinaryMatrix(grid1);
}