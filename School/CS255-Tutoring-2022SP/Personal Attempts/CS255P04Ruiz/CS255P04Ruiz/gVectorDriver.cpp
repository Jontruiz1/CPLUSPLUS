//gVectorDriver.cpp
#include <iostream>
#include "gVector.h"  //use gVector class
#include "CS255Exceptions.h"
using namespace std;

int main() {
	// this test declares and defines two types of gVector objects
	const int MIN_TEMP = -10;
	const int MAX_TEMP = 15;
	gVector<char> code('A', 'Z');
	gVector<double> fahrVector{ MIN_TEMP, MAX_TEMP };  //Alternate way of calling constructor

	// a very simple encryption of upper-case Latin letters
	for (char ch = 'A'; ch <= 'Z'; ch++) {
		code[ch] = ch + 5;
	}

	// tempVector [cel_temp] holds Fahrenheit equivalent of Celsius
	// temperature cel_temp. Conversion is F = 9/5 C + 32
	for (int cel_temp = MIN_TEMP; cel_temp <= MAX_TEMP; cel_temp++) {
		fahrVector[cel_temp] = 9.0 / 5.0 * cel_temp + 32.0;
	}

	// Show simple encryption shift
	cout << "Encryption Shift:" << endl;

	for (char ch = 'A'; ch <= 'Z'; ch++) {
		cout << ch;
	}

	cout << endl;

	for (char ch = 'A'; ch <= 'Z'; ch++) {
		cout << code[ch];
	}

	cout << endl << endl;

	// output the temperature conversions
	cout << "Temperature Conversion C - > F:" << endl;
	cout << "	C" << "	" << "F" << endl;

	for (int cel_temp = MIN_TEMP; cel_temp <= MAX_TEMP; cel_temp++) {
		cout.setf(ios::fixed, ios::floatfield);
		cout.precision(2);
		cout.width(7);
		cout << cel_temp << "	" << fahrVector[cel_temp] << endl;
	}

	return 0;
}
