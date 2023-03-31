#include <string>

std::string encrypt(const std::string& input, int a, int shift){

    std::string output = "";
    
    for(const char& c : input){
        char curr;
        // this is ugly, I would never do this if I wanted to actually read the code but I just thought it was funny
        output += isalpha(c) ? (( curr = ( a * (c - 'a') + shift) % 26 ) < 0 ? curr += 26 : 0), curr += 'a' : curr = c;
    }
    return output;

}

std::string decrypt(const std::string& input, int a, int shift){

    std::string output = "";
    
    for(const char& c : input){
        char curr;
        // this is ugly, I would never do this if I wanted to actually read the code but I just thought it was funny
        output += isalpha(c) ? (( curr = ( ( (c - 'a') - shift) / a ) % 26 ) < 0 ? curr += 26 : 0), curr += 'a' : curr = c;
    }
    return output;

}