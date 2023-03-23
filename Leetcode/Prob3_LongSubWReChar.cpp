#include <string>

using namespace std;

int lengthOfLongestSubstring(string s) {
        string check = s;
    string result;
    string temp;
    
    int j;
    int longest = 0;
    int counter = 0;

    for(int i = 0; i < check.length(); i++){
        temp = check[i];
        counter = 0;
        j = i+1;
        if(temp.find(check[j] == string::npos)){
            counter = 1;
            while( temp.find(check[j]) == string::npos && !(j >= check.length()) ){
                temp += check[j];
                counter++;
                j++;
            }
        }
        
        if(counter > longest){
            longest = counter;
        }
    }
    if(check.length() > 0 && longest == 0){
        longest = 1;
    }
    return longest;
    }