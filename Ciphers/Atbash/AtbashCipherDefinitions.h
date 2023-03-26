#include <string>

using namespace std;

string encrypt(string input){
    string output = "";
    string alphabet = "abcdefghijklmnopqrstuvwxyz";
    string reverse = "zyxwvutsrqponmlkjihgfedcba";
    
    for(const char& c : input){
        char curr;
        auto pos = alphabet.find(c);

        curr = c;
        if(pos != string::npos) curr = reverse[pos];
        output += curr;
    }
    return output;
}

string decrypt(string input){
    string output = "";
    string alphabet = "abcdefghijklmnopqrstuvwxyz";
    string reverse = "zyxwvutsrqponmlkjihgfedcba";
    
    for(const char& c : input){
        char curr;
        auto pos = reverse.find(c);
        
        curr = c;
        if(pos != string::npos) curr = alphabet[pos];
        output += curr;
    }
    return output;
}