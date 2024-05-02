#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class Solution {
private:
    string mid = "";
    int result = 0;
    int sign = 1;
    int start = 0;
public:
    int myAtoi(string s) {
        char ws = ' ';
        s.erase(0, s.find_first_not_of(ws));

        if(s[0] == '+'){
            sign = 1; start = 1;
        }
        else if(s[0] == '-') {
            sign = -1; start = 1;
        }

        for(int i = start; i < s.length(); ++i){
            if(isalpha(s[i]) || s[i] == '.' || s[i] == '+' || s[i] == '-' || s[i] == ' ') break;
            mid += s[i];
        }
        if(mid.empty()) return 0;

        try{
            result = stoi(mid) * sign;
        }
        catch(out_of_range e){
            if(sign < 0) result = -pow(2, 31);
            else{
                result = pow(2, 31) - 1;
            }
        }

        return result;
    }
};

int main(){

    Solution s;
    cout << s.myAtoi("+-    12");
}
