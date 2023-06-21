#include <iostream>
#include <vector>

using namespace std;

class Solution{
private:
    vector<int> values{1000, 500, 100, 50, 10, 5, 1};
    vector<char> symbols{'M', 'D', 'C', 'L', 'X', 'V', 'I'};

public:
    string intToRoman(int num){
        string result = "";
        
        for(int i = 0; i < values.size() && num != 0; ++i){
            int toGo = num / values[i];
            if(toGo > 0){
                for(int j = 0; j < toGo; ++j){
                    result += symbols[i];
                }
                num -= toGo * values[i];
            }
            else{
                
            }
        }
        return result;
    }
};

int main(){
    Solution test;
    std::cout << test.intToRoman(1499);
    return 0;
}
