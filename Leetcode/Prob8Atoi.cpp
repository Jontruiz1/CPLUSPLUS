#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <sstream>

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
            if( (curr[i] == '-' || curr[i] == '+')){
                if(!sign){
                    result += curr[i];
                    sign = true;
                }
                return "";
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

    std::istringstream iss (curr);
    iss >> result;
    if(result == INT_MAX || result == INT_MIN) return INT_MIN;
    
    
    return result;
}


int main(){
    cout << myAtoi("      -42");
}