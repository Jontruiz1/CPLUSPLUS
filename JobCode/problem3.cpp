#include <iostream>
#include <string>

const char* PlayerNames[] = 
{
               "Scorpion",
               "SubZero",
               "LiuKang"
};

bool IsValidPlayer(const char* player)
{

    for (const char* p : PlayerNames) {
        if (p == player) return true;
    }

    return false;

}


int main(){
    const char* a = "Scorpion";
    const char* b = "Invalid";
    const char* c = "1";
    const char* d = "@";

    std::cout << IsValidPlayer(a);

}