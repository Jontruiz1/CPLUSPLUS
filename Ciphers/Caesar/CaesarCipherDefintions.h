#include <string>

using namespace std;

string encrypt(string input, int shift){
    string output = "";
    
    for(const char& c : input){
        char curr;
        /*
        // this is equivalent to the ugly one-liner
        // if the letter is in the alphabet shift the character
        if(isalpha(c)){
            curr = (( (c - 'a') + shift) % 26);
            // if the shift was backwards and made it negative, add 26 and then 'a' to get back to the ascii value
            if(curr < 0) curr += (26);
            curr += 'a';
        }
        else{
            // just put the nonalphabetic character back
            curr = c;
        }*/

        // this is ugly, I would never do this if I wanted to actually read the code but I just thought it was funny
        output += isalpha(c) ? (( curr = ( (c - 'a') + shift) % 26 ) < 0 ? curr += 26 : 0), curr += 'a' : curr = c;
    }
    return output;
}


string bruteforceDecrypt(string input){
    string output = "\nPossible solutions: \n";
    for(int i = 1; i <= 26; ++i){
        for(const char& c : input){
            char curr;
        /*
        // this is equivalent to the ugly one-liner
        // if the letter is in the alphabet shift the character
        if(isalpha(c)){
            curr = (( (c - 'a') + shift) % 26);
            // if the shift was backwards and made it negative, add 26 and then 'a' to get back to the ascii value
            if(curr < 0) curr += (26);
            curr += 'a';
        }
        else{
            // just put the nonalphabetic character back
            curr = c;
        }*/
            // this is ugly, I would never do this if I wanted to actually read the code but I just thought it was funny
            output += isalpha(c) ? (( curr = ( (c - 'a') - i) % 26 ) < 0 ? curr += 26 : 0), curr += 'a' : curr = c;
        }
        output += "\nThis was shifted " + to_string(i) + " characters\n\n";
    }
    
    return output;
}

string decrypt(string input, int shift){
    string output = "";
    
    for(const char& c : input){
        char curr;
        /*
        // this is equivalent to the ugly one-liner
        // if the letter is in the alphabet shift the character
        if(isalpha(c)){
            curr = (( (c - 'a') + shift) % 26);
            // if the shift was backwards and made it negative, add 26 and then 'a' to get back to the ascii value
            if(curr < 0) curr += (26);
            curr += 'a';
        }
        else{
            // just put the nonalphabetic character back
            curr = c;
        }*/

        // this is ugly, I would never do this if I wanted to actually read the code but I just thought it was funny
        output += isalpha(c) ? (( curr = ( (c - 'a') - shift ) % 26 ) < 0 ? curr += 26 : 0), curr += 'a' : curr = c;
    }
    return output;
}
