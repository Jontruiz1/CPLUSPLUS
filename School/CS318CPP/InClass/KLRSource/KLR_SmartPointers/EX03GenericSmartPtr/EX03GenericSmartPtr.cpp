// EX03GenericSmartPtr
#include <iostream>
#include <vector>
#include <string>
#include "Box.h"
#include "SmartPtr.h"
using namespace std;

int main()
{
    SmartPtr<Box> ptr(new Box(5, 2, 3));
    cout << "Box: " << *ptr << "\n";
    cout << "Volume: " << ptr->getVolume() << "\n";

    // ptr goes out of scope, its destructor is called which calls delete (ptr)

    cin.get();
    return 0;
}