//EX04Scope
/*
*/
#include <iostream>
using namespace std;

// Variables declared outside of a function are global variables
int x{}; 
int y{ 20 };
bool isCorrect;


int main()
{
    //local variable 
    int a{ 5 };

    cout << "a is " << a << "\n";

    // global variables can be seen and used everywhere in the file
    cout << "\nx is " << x << "\n";
    cout << "y is " << y << "\n";
    cout << "isCorrect is " << isCorrect << "\n";

    isCorrect = true;
    cout << boolalpha; //print bool out as "true" or "false"
    cout << "\nisCorrect is " << isCorrect << "\n";

    //local variable x hides the global
    int x = 50;
    cout << "\nx is " << x << "\n";

    //get to global x with scope resolution operator
    cout << "\nGlobal x is " << ::x << "\n";

	cin.get();
	return 0;
}