#include <iostream>

using namespace std;

bool is_palindrome(const string& s){
    int i = 0;
    int j = s.length()-1;

    while(!(i >= j)){
        if(s[i] != s[j]){
            return false;
        }
        ++i;
        --j;
    }
    return true;
}
