#include <string>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

/*given a string s, return the longest palindromic substring in s
a string is palindromic if it reads the same forwards and backwards
*/

// make a function to check if a string is a palindrome in the first place

bool isPalindrome(string s){
    string temp = s;
    reverse(s.begin(), s.end());
    return temp == s;
}


vector<string> substrings(const string& input){
    vector<string> result = {};

    for(int i = 0; i < input.size(); ++i){
        for(int j = 0; j < input.size(); ++j){
            if(isPalindrome(input.substr(i, j))) result.push_back(input.substr(i, j));
        }
    }
    sort(result.begin(), result.end(), 
    [](const string& a, const string& b){
        return (a.size() > b.size());
    }
    );

    return result;
}


string longestPalindrome(string s) {
    vector<string> substringed = substrings(s);
    for(const string& curr : substringed){
        if(isPalindrome(curr)) return curr;
    }
    return "";



}

int main(){
    string longest = longestPalindrome("abcdbbfcba");
    vector<string> substringed = substrings("abcdbbfcba");
    //cout << longest;
    for(string i : substringed) {
        cout << i << endl;
    }
}