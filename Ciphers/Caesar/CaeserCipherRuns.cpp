#include <iostream>
#include "CaesarCipherDefintions.h"


int main(){
    int shift;
    char choice;
    std::string message;
    std::string decrypted;
    std::cout << "Caesar Cipher Encrypter/Decrypter!\n\n";
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
        
        std::cout << "How many letters would you like to shift the message by? (negative to shift backwards): ";
        std::cin >> shift;
        std::string encrypted = encrypt(message, shift);
        std::cout << "Encrypted string is: " << encrypted;
    }
    else{
        std::cin.ignore();
        std::cout << "Enter the encrypted string: ";
        std::getline(std::cin, message);
        std::cout << "Do you know how many letters the original message was shifted by? (y/n) ";
        std::cin >> choice;
        while(choice != 'y' && choice != 'n'){
            std::cout << "Please enter a valid choice: ";
            std::cin >> choice;
        }
        
        if(choice == 'y'){
            std::cout << "Enter the number of characters the original message was shifed by: ";
            std::cin >> shift;

            decrypted = decrypt(message, shift);
            std::cout << "Decrypted string is: " << decrypted;
        }
        else{
            std::cout << "Bruteforcing encrypted string: ";
            std::cout << bruteforceDecrypt(message);
        }
    }

}