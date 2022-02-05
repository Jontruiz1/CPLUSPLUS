// StaticLocal
// Static variable is created at the start of the program, 
// and destroyed at the end of the program (just like a global variable). 
// Retains its value after it goes out of scope
#include <iostream>
using namespace std;

void displayLocals()
{
    static int val1{ 1 }; 
    int val2{ 1 };
    ++val1;
    ++val2;
    cout << "\nStatic val1 is " << val1 << '\n';
    cout << "Automatic val2 is " << val2 << '\n';

} // value is destroyed here

int main()
{
    displayLocals();
    displayLocals();
    displayLocals();

    return 0;
}