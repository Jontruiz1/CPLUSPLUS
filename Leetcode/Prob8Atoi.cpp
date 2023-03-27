#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;
string alphaRemove(const string& s){
    string mid = "";
    if(isalpha(s[0])) return mid;
    for(int i = 0; i < s.size(); ++i){
        if((!isalpha(s[i]) && s[i] != 32 ) || s[i] == '-' || s[i] == '+') mid += s[i];
    }

    return mid;
}

string signAndCut(const string& curr){
    string result = "";
    bool leading = true;
    bool sign = false;
    for(int i = 0; i < curr.size(); ++i){
        if(curr[i] != '0' || !leading) {
            if( (curr[i] == '-' || curr[i] == '+') && !sign ){
                result += curr[i];
                sign = true;

            }
            else if(curr[i] != '-' && curr[i] != '+'){
                result += curr[i];
                leading = false;
            }
        }
    }
    return result;
}

int myAtoi(string s){
    string curr = alphaRemove(s);
    curr = signAndCut(curr);
    size_t strSize = curr.size();
    int result = 0;
    int exp = 0;
    for(int i = strSize-1; i >= 0; --i){
        if(curr[i] == '-' || curr[i] == '+') {
            continue;
        }

        int temp = ((curr[i] - 48) * pow(10, exp));
        if(temp == INT_MIN || temp == INT_MAX){
            result += temp;
            ++exp;
        }

    }
    if(curr[0] == '-') result*=-1;
    return result;
}


int main(){
    cout << myAtoi("-91283472332");
}