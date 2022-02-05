// EX04UniquePtr 
#include <iostream> 
#include <memory> // needed for move function
#include "Box.h"
using namespace std;

int main()
{
    unique_ptr<Box> p1(new Box(3,4,5));
    cout << "\nOwned by p1" << endl;
    cout << "\tBox Dimensions: " << *p1 << endl;
    cout << "\tVolume: " << p1->getVolume() << endl;
    cout << "\tMemory address in p1: " << p1 << endl;

    // Can't do this
    // unique_ptr<Box> p2 = p1;

    //// transfers ownership to p2 
    unique_ptr<Box> p2 = move(p1);
    cout << "\nOwnership transfered to p2" << endl;
    cout << "\tBox Dimensions: " << *p2 << endl;
    cout << "\tMemory address in p1: " << p1 << endl;
    cout << "\tMemory address in p2: " << p2 << endl;

    //// transfers ownership to p3 
    unique_ptr<Box> p3 = move(p2);

    cout << "\nOwnership transfered to p3" << endl; 
    cout << "\tBox Dimensions: " << *p3 << endl;
    cout << "\tMemory address in p1: " << p1 << endl;
    cout << "\tMemory address in p2: " << p2 << endl;
    cout << "\tMemory address in p2: " << p3 << endl;

    cin.get();
    return 0;
}
