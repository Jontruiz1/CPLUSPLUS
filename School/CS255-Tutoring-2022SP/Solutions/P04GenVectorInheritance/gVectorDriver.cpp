// SOLUTION: gVectorDriver.cpp
#include <iostream>
#include "gVector.h"  //use gVector class 
#include "CS255Exceptions.h"

using namespace std;

int main()
{	// declare two types of gVector objects 
	const int MIN_TEMP = -10;
	const int MAX_TEMP = 15;
	gVector<char> code{ 'A', 'Z' };
	gVector<double> fahrVector{ MIN_TEMP, MAX_TEMP }; //alternate way of calling constructor

													  // a very simple encryption of upper-case Latin letters
	for (char ch = 'A'; ch <= 'Z'; ch++)
		code[ch] = ch + 5;

	// tempVector [cel_temp] holds Fahrenheit equivalent of Celsius
	// temperature cel_temp. conversion is F = 9/5 C + 32
	for (int cel_temp = MIN_TEMP; cel_temp <= MAX_TEMP; cel_temp++)
		fahrVector[cel_temp] = 9.0 / 5.0 * cel_temp + 32.0;

	// Show simple encryption shift 
	cout << "Encryption Shift:" << endl;
	for (char ch = 'A'; ch <= 'Z'; ch++)
		cout << ch;
	cout << endl;
	for (char ch = 'A'; ch <= 'Z'; ch++)
		cout << code[ch];
	cout << endl << endl;

	// output the temperature conversions 
	cout << "Temperature Conversion C - > F:" << endl;
	cout << "      C" << "    " << "F" << endl;
	for (int cel_temp = MIN_TEMP; cel_temp <= MAX_TEMP; cel_temp++) {
		cout.setf(ios::fixed, ios::floatfield);
		cout.precision(2);
		cout.width(7);
		cout << cel_temp << "  " << fahrVector[cel_temp] << endl;
	}
	cout << "Testing resize: \n";
	fahrVector.resize(MIN_TEMP - 10, MAX_TEMP + 15); cout << "Test resize worked\n";
	//Extra Tests for grading students programs
	cout << "Extra Test 1:";
	const int MIN_TEMP2 = -100;
	const int MAX_TEMP2 = -80;
	gVector<double> fahrVector1{ MIN_TEMP2, MAX_TEMP2 };
	for (int i = MIN_TEMP2; i < MAX_TEMP2; i++) {
		fahrVector1[i] = i - 10;
	}
	for (int j = MIN_TEMP2; j <= MAX_TEMP2; j++) {
		if (j % 5 == 0) cout << endl;
		cout.setf(ios::fixed, ios::floatfield);
		cout.precision(2);
		cout.width(7);
		cout << fahrVector1[j] << " ";
	}
	cout << endl;
	cout << "Extra Test 2:\n";
	enum Colors { RED = 0x255 << 16, GREEN, BLUE, CYAN, YELLOW, MAGENTA, BLACK };
	size_t NUMBER_OF_COLORS = 7;
	gVector<string> colorMapping{ Colors::RED, Colors::BLACK };
	colorMapping[RED] = "RED";
	colorMapping[GREEN] = "GREEN";
	colorMapping[BLUE] = "BLUE";
	colorMapping[CYAN] = "CYAN";
	colorMapping[YELLOW] = "YELLOW";
	colorMapping[MAGENTA] = "MAGENTA";
	colorMapping[BLACK] = "BLACK";
	for (unsigned k = RED; k < RED + NUMBER_OF_COLORS; k++)
		cout << colorMapping[k] << endl;
	cout << endl;


	return 0;
}
