#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    vector<int> nums = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4 ,1 };
    vector<string> numerals = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    const int SZ = 13;
    string result = "";
public:

    // I = 1
    // V = 5
    // X = 10
    // L = 50
    // C = 100
    // D = 500
    // M = 1000

    // usually largest to smallest, left to right
    // For 4, subtract I from V = IV; for 9, subtract I from X = IX
    // For 40, subtract X from L = 40; for 90, subtract X from C = 90
    // For 400, subtract C from D = 400; for 900, subtract C from M = 900

    string intToRoman(int num) {
        for(int i = 0; i < SZ; ++i){
            int num_divisible = num / nums[i];
            int to_subtract = num_divisible * nums[i];

            if(num_divisible != 0){
                num -= to_subtract;
                for(int j = 0; j < num_divisible; ++j){
                    result.append(numerals[i]);
                }
            }
        }

        return result;
    }
};

int main(){
    Solution a;

    cout<< a.intToRoman(1994);
}