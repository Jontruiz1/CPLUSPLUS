#include <string>

std::string encrypt(const std::string& input){
    std::string output = "";
    std::string alphabet = "abcdefghijklmnopqrstuvwxyz";
    std::string reverse = "zyxwvutsrqponmlkjihgfedcba";
    
    for(const char& c : input){
        char curr;
        auto pos = alphabet.find(c);

        curr = c;
        if(pos != std::string::npos) curr = reverse[pos];
        output += curr;
    }
    return output;
}

std::string decrypt(const std::string& input){
    std::string output = "";
    std::string alphabet = "abcdefghijklmnopqrstuvwxyz";
    std::string reverse = "zyxwvutsrqponmlkjihgfedcba";
    
    for(const char& c : input){
        char curr;
        auto pos = reverse.find(c);
        
        curr = c;
        if(pos != std::string::npos) curr = alphabet[pos];
        output += curr;
    }
    return output;
}