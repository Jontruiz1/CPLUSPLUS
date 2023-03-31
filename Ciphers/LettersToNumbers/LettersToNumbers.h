#include <string>
#include <iostream>

std::string encrypt(const std::string& input){
    std::string output = "";
    
    for(const char& c : input){
        
        // this is ugly, I would never do this if I wanted to actually read the code but I just thought it was funny

        output += (isalpha(c) ? (std::to_string(int(c-'a')) + " ") : (c + ""));

        //output += (isalpha(c) ? (  (c - 'a') + '0') : curr = c);
    }

    return output;
}