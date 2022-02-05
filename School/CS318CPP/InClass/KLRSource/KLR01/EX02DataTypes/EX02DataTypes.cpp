//EX02DataTypes

#include <iostream>
using namespace std;

int main() {
	// number of bytes used for each type
	cout << "Size of char : " << sizeof(char) << endl;
	cout << "Size of bool : " << sizeof(bool) << endl;
	cout << "Size of int : " << sizeof(int) << endl;
	cout << "Size of short int : " << sizeof(short int) << endl;
	cout << "Size of long int : " << sizeof(long int) << endl;
	cout << "Size of float : " << sizeof(float) << endl;
	cout << "Size of double : " << sizeof(double) << endl;
	cout << "Size of wchar_t : " << sizeof(wchar_t) << endl;

	enum colors { black, blue, green, cyan, red, purple, yellow, white };

	colors mycolor;

	mycolor = green;
	cout << "\nmyColor is " << mycolor << endl;

	if (mycolor == green) 
		mycolor = red;

	cout << "myColor is " << mycolor << endl;

	cin.get();
	return 0;
}