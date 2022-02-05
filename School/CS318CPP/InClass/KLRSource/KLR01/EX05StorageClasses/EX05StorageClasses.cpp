//EX05StorageClasses

#include <iostream>
#include <string>
using namespace std;

static int counter = 10; // global static variable
void displayCounter(); // function declaration
string message;
extern void displayMessage();

int main() {
    // stops when count is 0
    while (counter--) { 
        displayCounter();
    }

    message = "Welcome to Oz";
    displayMessage();

    cin.get();
    return 0;
}

// Function definition
void displayCounter(void) {
    static int i = 0; // local static variable
    i++;
    cout << "i is " << i << " and counter is " << counter << std::endl;
}