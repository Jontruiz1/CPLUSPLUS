#include <iostream>
#include "CaesarCipherDefintions.h"


int main(){
    string encrypted = "iq ifcc vqqr fb rdq vfllcq na rdq cfjwhwz hr bnnb hcc hwwhbsqvqbre hwq vhlq";

    //string encrypted = encrypt(input, shift);
    //cout << endl <<  encrypted << endl;

    cout << "Bruteforce: ";
    cout << bruteforceDecrypt(encrypted);

}