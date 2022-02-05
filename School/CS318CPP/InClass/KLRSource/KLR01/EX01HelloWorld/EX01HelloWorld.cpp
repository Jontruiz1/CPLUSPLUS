//EX01HelloWorld
#include <iostream> //directive to use this standard library
using namespace std; //will discuss more on this later

/*
 General Notes:
	{} surround blocks
	return 0 -- indicates clean execution
	<< insertion operator used with streams -- more on this later
	; ends statements
*/

// main() -- function executed at start
int main() {
	cout << "Hello World" << endl; // displays message on the console
	// std::cout << "Hello World";   Using namespace std allows us not to have to specify std::
	cin.get();  //may need this to keep window open on Windows
	return 0;
}