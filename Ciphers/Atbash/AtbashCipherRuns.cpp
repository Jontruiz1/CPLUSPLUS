#include <iostream>
#include "AtbashCipherDefinitions.h"

int main(){
    string input;
    cout << "Enter a string to encrypt: ";
    getline(cin, input);
    for(char& c : input) c = tolower(c);

    string encrypted = encrypt(input);
    cout << encrypted << endl;

    string decrypted = decrypt(encrypted);
    cout << decrypted;

}