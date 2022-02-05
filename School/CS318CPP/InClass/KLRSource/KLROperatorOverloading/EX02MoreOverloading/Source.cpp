// EX02MoreOverloading 
#include <iostream>
#include "Box.h"

int main() {
    Box box1{ 6.0, 7.0, 5.0 };
    Box box2{ 12.0, 13.0, 10.0 };
    Box box3;

    cout << "Box 1 Dimensions: " << box1 << endl;
    cout << "Box 2 Dimensions: " << box2 << endl;
    cout << "Box 3 Dimensions: " << box3 << endl;

    box3 = box1 + box2;
    cout << "\nResults after this executes: box3 = box1 + box2";
    cout << "\n\tBox 3 Dimensions: " << box3 << endl;

    box1 += box3;
    cout << "\nResults after this executes: box1 += box3";
    cout << "\n\tBox 1 Dimensions: " << box1 << endl;

    Box box4 = box1 + box2 + box3;
    cout << "\nResults after this executes: Box box4 = box1 + box2 + box3";
    cout << "\n\tBox 1 Dimensions: " << box1 << endl;
    cout << "\tBox 2 Dimensions: " << box2 << endl;
    cout << "\tBox 3 Dimensions: " << box3 << endl;
    cout << "\tBox 4 Dimensions: " << box4 << endl;

    cin.get();
    return 0;
}