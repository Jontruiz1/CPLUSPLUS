#include <iostream>
#include "AtbashCipherDefinitions.h"

int main(){
    int shift;
    char choice;
    std::string message;
    std::string decrypted;
    std::cout << "Atbash Cipher Encrypter/Decrypter!\n\n";
    std::cout << "Would you like to encrypt or decrypt a string?(e/d): ";
    
    std::cin >> choice;
    while(choice != 'e' && choice != 'd'){
        std::cout << "Please enter a valid choice: ";
        std::cin >> choice;
    }

    if(choice == 'e'){
        std::cin.ignore();
        std::cout << "Enter a string to encrypt: ";
        std::getline(std::cin, message);
        
        std::string encrypted = encrypt(message);
        std::cout << "Encrypted string is: " << encrypted;
    }
    else{
        std::cin.ignore();
        std::cout << "Enter the encrypted string: ";
        std::getline(std::cin, message);

        decrypted = decrypt(message);
        std::cout << "Decrypted string is: " << decrypted;
    }

}