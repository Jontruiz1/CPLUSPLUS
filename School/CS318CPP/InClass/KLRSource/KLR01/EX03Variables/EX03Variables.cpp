//EX03Variables
/*
*	Notes:  
*		Define and initialize variables closer to where they are used
*		Always initialize variables
*/

#include <iostream>
using namespace std;

//declaration only ... will see more on this later.  Basically means that the "definition" will occur
//	somewhere else ... possibly another file... but can only be defined once.
extern string fileName;

int main() {
	//definition and declaration 
	int a;
	// definition and declaration of multiple variables at once ... be careful with this
	int b, c;

	a = 20;
	b = a + 1;
	c = a + 2;

	cout << "a is " << a << endl;
	cout << "b is " << b << endl;
	cout << "c is " << c << endl;


	//declaration
	int width;
	//initialization
	width = 5;
	cout << "\nwidth is " << width << endl;

	int length{ 6 }; //brace initialization ... not in earlier versions of C++
	//int length = 6;  //copy initialization
	//int length = { 6 }; //copy brace initialization -- not used often
	cout << "\nlength is " << length << endl;

	//int age{5.5}; //not a good idea ... loss of data

	cin.get();
	return 0;
}