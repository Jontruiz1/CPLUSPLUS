#include <iostream>
#include <vector>

using namespace std;

string convert(string s, int numRows){
    if(numRows == 1) return s;
    vector<vector<char>> zigzag(numRows);
    string result = "";
    size_t j = 0;
    bool back = false;
    
    for(int i = 0; i < numRows; (back ? --i : ++i), ++j){
        if(j == s.size()) break;
        if(i == (numRows-1) ) back = true;
        if(i == 0) back = false;
        zigzag[i].push_back(s[j]);
    }

    for(int i = 0; i < numRows; ++i){
        for(int j = 0; j < zigzag[i].size(); ++j){
           result += zigzag[i][j];
        }
    }
    return result;
}

int main(){
    cout << convert("ab", 1);

}