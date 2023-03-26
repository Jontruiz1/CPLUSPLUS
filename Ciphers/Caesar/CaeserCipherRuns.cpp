#include "CaeserCipherDefintions.h"


int main(){
    string input;
    
    cout << "Enter a string to encrypt: ";
    getline(cin, input);
    for(char& c : input) c = tolower(c);

    cout << "Enter a number you wish to shift the sentence by (negative for backwards, positive for forwards): ";
    int shift;
    cin >> shift;

    string encrypted = encrypt(input, shift);
    cout << endl <<  encrypted << endl;

    cout << "Bruteforce: ";
    cout << bruteforceDecrypt(encrypted);


}