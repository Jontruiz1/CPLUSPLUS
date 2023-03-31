#include <iostream>
#include "LettersToNumbers.h"

int main(){
    std::string input;
    std::cout << "Enter a message to encrypt: ";
    std::getline(std::cin, input);

    std::cout << "Message encrypted: ";
    std::cout << encrypt(input);

}