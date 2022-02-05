// EX02SimpleSmartPtr
#include <iostream>
#include "Box.h"
#include "SmartPtr.h"
using namespace std;

int main()
{
    SmartPtr ptr(new Box(5,2,3));
    cout << "Box: " << *ptr << "\n";

    // ptr goes out of scope, its destructor is called which calls delete (ptr)

    cin.get();
    return 0;
}
