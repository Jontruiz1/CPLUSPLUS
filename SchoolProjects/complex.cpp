/*
Jonathan Ruiz
CS318
P03
Complex Numbers
*/

#include "complex.h"
#include <iostream>
#include <cmath>
#include <assert.h>
#include <cmath>
#include <string>
#include <ostream>;

using namespace std;

namespace MY_MATH{
	const double PI = 3.141592653589793;
}

complex f(const complex& z)
{
	return z * z * z - 3 * z * z + 4 * z - 2;
}

//approx_value is used for testing equivalent values of type double
inline bool approx_value(double x, double y) {
	return (y - .0001 <= x && x <= y + .0001);
}
bool assertx(bool expr, unsigned line) {
	if (!expr) cerr << "Error at line" << line << endl; return expr;
}

int main() {
	const complex x(0, 1); // complex number i = 0 + 1i
	complex z1, z2, z3, z6, z7;
	complex z4 = complex(1, 2);
	complex complex_number[] = { complex(2,3), complex(-1,1), complex(1,1),
	complex(1,-1), complex(1,0) };
	complex sum = 0.0;
	double x1;
	double y1;
	//testing assignment-related operators
	z1 = complex{ 3, 2 };
	z2 = complex{ -4, 3 };
	z4 = z3;
	z3 += z2;
	assertx(z3 == z2, __LINE__);
	z3 -= z2;
	assertx(z4 == z3, __LINE__);
	z3 *= z2;
	z3 /= z2;
	assertx(z3 == z4, __LINE__);
	x1 = z3.real();
	y1 = z3.imag();
	const double C = 3.0;
	z3 += C;
	assertx((z3.real() == (x1 + C)) && (z3.imag() == y1), __LINE__);
	z3 -= C;
	assertx((z3.real() == x1) && (z3.imag() == y1), __LINE__);
	z3 *= C;
	assertx((z3.real() == (x1 * C)) && (z3.imag() == (y1 * C)), __LINE__);
	z3 /= C;
	assertx((z3.real() == x1) && (z3.imag() == y1), __LINE__);

	//extra comparison
	assertx(z3 != z2, __LINE__);
	assertx(z4 != z2, __LINE__);
	assertx(z2 != z1, __LINE__);

	//extra tests (infix tests)
	//binary addition tests
	z3 = complex{ 12, 50 };
	z2 = complex{ -5, -12 };
	assertx((z3 + z2) == (complex(7, 38)), __LINE__);
	assertx((z3 + C) == complex(15, 50), __LINE__);
	z3 = complex(-34, 10);
	assertx(C + z3 == complex(-31, 10), __LINE__);

	//printing out z3 and z2
	cout << "z3 after binary addition tests: " << z3;
	cout << "z3 after binary addition tests: " << z2 << endl;

	//binary subtraction tests
	z3 = complex{ 30, -5 };
	z2 = complex{ -16, 20 };
	assertx((z3 - z2) == (complex(46, -25)), __LINE__);
	assertx((z3 - C) == complex(27, -5), __LINE__);
	assertx((C - z3) == complex(-27, 5), __LINE__);

	//printing out z3 and z2
	cout << "z3 after binary subtraction tests: " << z3;
	cout << "z3 after binary subtraction tests: " << z2 << endl;

	//binary multiplication tests
	z3 = complex{ 14, 23 };
	z2 = complex{ -5, -23 };
	assertx((z3 * z2) == (complex(459, -437)), __LINE__);
	assertx((z3 * C) == complex(42, 69), __LINE__);
	assertx((C * z2) == complex(-15, -69), __LINE__);

	//printing out z3 and z2
	cout << "z3 after binary multiplication tests: " << z3;
	cout << "z3 after binary multiplication tests: " << z2 << endl;

	z3 = complex(6, 42);
	z2 = complex(3, 7);

	assertx(z3 / z2 == complex(312./58, 84./58), __LINE__);
	assertx((z3 / C) == (complex(2, 14)), __LINE__);
	assertx((C / z3) == complex(18./1800, -126./1800), __LINE__);
 
	//printing out z3 and z2
	cout << "z3 after binary division tests: " << z3;
	cout << "z3 after binary division tests: " << z2 << endl;

	//testing infix operators
	z3 = complex{ 10, -4 };
	z2 = complex{ -4, 3 };
	assertx((z1 + z2) == complex(-1, 5), __LINE__);
	assertx(z1 == complex(3, 2), __LINE__);
	assertx(z2 == complex(-4, 3), __LINE__);
	z1 = complex{ 2, 3 }; //note change of value bound to z1
	assertx(z1.real() == 2.0, __LINE__);
	assertx(z1.imag() == 3.0, __LINE__);
	assertx(real(z1) == 2.0, __LINE__);
	assertx(imag(z1) == 3.0, __LINE__);
	assertx(z1.magnitude() == sqrt(z1.real() * z1.real() + z1.imag() * z1.imag()), __LINE__);

	//print out z3 and z2
	cout << "z3 after infix operator tests: " << z3;
	cout << "z3 after infix operator tests: " << z2 << endl;

	//other helper functions test
	z3 = complex(-42, -4);
	z2 = complex(10, 4);

	double rea = 5;
	double theta = 50;

	assertx(real(z3) == z3.real(), __LINE__);
	assertx(imag(z3) == z3.imag(), __LINE__);
	assertx(norm(z3) == pow(z3.magnitude(), 2), __LINE__);
	assertx(conj(z3) == complex(z3.real(), z3.imag() / -1), __LINE__);
	assertx(polar(rea, theta) == complex(rea * cos(theta), rea * sin(theta)), __LINE__);
	assertx(polar(rea) == complex(rea, 0), __LINE__);

	assertx(arg(complex(1., 0.)) == 0.0, __LINE__);
	assertx(approx_value(arg(complex(0, 1)), MY_MATH::PI / 2.0), __LINE__);
	assertx(approx_value(arg(complex(-1, 0)), MY_MATH::PI), __LINE__);

	cout << "z3 after other helper function tests: " << z3;
	cout << "z3 after other helper function tests: " << z2 << endl;

	assertx(f(complex_number[0]) == complex(-25, -15), __LINE__);
	assertx(f(complex_number[1]) == complex(-4, 12), __LINE__);

	//unary tests
	cout << "Addition unary test +z3 =  " << z3;
	cout << "Subtraction unary test -z3 = " << -z3 << endl;

	//test insertion and extraction

	cout << "Enter a complex number z1 of form (a, b): ";
	cin >> z6;
	cout << "Enter a complex number z2 of form (a, b): ";
	cin >> z7;

	cout << z6;
	cout << z7;

	//check if z1 and z2 were initialized to be complex numbers
	assertx(typeid(z6) == typeid(complex), __LINE__);
	assertx(typeid(z7) == typeid(complex), __LINE__);
	return 0;
}

//constructors
complex::complex() {
	this->re = 0;
	this->im = 0;
}
complex::complex(double a) {
	this->re = a;
	this->im = 0;
}
complex::complex(double a, double b) {
	this->re = a;
	this->im = b;
}
complex::complex(const complex& c) {
	this->re = c.real();
	this->im = c.imag();
}

//assignment operators and reference returns
complex& complex::operator= (const complex& rhs) {
	this->re = rhs.real();
	this->im = rhs.imag();
	return *this;
}
complex& complex::operator+= (const complex& z){
	this->re += z.real();
	this->im += z.imag();
	return *this;
}
complex& complex::operator-= (const complex& z) {
	this->re -= z.real();
	this->im -= z.imag();
	return *this;
}
complex& complex::operator*= (const complex& z) {
	//u, v, y and x for the values on wikipedia
	double x = this->re;
	double y = this->im;

	double u = z.real();
	double v = z.imag();

	this->re = (x * u) - (y * v);
	this->im = (x * v) + (y * u);
	return *this;
}
complex& complex::operator/= (const complex& z) {
	//u, v, y and x for the values on wikipedia
	double u = this->re;
	double v = this->im;

	double x = z.real();
	double y = z.imag();

	this->re = (u * x + v * y) / (pow(x, 2) + pow(y, 2));
	this->im = (v * x - u * y) / (pow(x, 2) + pow(y, 2));

	return *this;
}

//conversions and reference returns
complex& complex::operator+= (const double x) {
	this->re += x;
	return *this;
}
complex& complex::operator-= (const double x) {
	this->re -= x;
	return *this;
}
complex& complex::operator*= (const double x) {
	this->re *= x;
	this->im *= x;
	return *this;
}
complex& complex::operator/= (const double x) {
	this->re /= x;
	this->im /= x;
	return *this;
}

//accessors
double complex::real() const {
	return re;
}
double complex::imag() const {
	return im;
}
double complex::magnitude() const {
	return sqrt(pow(this->real(), 2) + pow(this->imag(), 2));
}

//comparison helper functions
bool operator== (const complex& z1, const complex& z2) {
	return z1.real() == z2.real() && z1.imag() == z2.imag();
}
bool operator!= (const complex& z1, complex& z2) {
	return !(z1 == z2);
}

//i/o helper functions
istream& operator>> (istream& input, complex& z) {
	string line;
	double a;
	double b;

	getline(input, line);

	int comDel = line.find(",");
	int fParenDel = line.find("(");
	int sParenDel = line.find(")");

	try {
		a = stod(line.substr(1, comDel));
		b = stod(line.substr(comDel + 1, sParenDel - comDel));
	}
	catch (exception invalid_argument) {
		cout << "Invalid character";
	}
	
	z = complex(a, b);

	return input;
}
ostream& operator<< (ostream& output, const complex& z) {
	output << "(" << z.real() << ", " << z.imag() << ")" << endl;
	return output;
}

// binary helper functions, use +=, -=, *=, /=
complex operator+ (const complex& z1, const complex& z2) {
	complex sum = (z1);
	sum += z2;

	return sum;
}
complex operator+ (const complex& z1, const double x){
	complex sum(z1);
	sum += x;

	return sum;
}
complex operator+ (const double x, const complex& z){
	complex sum(x);
	sum += z;

	return sum;
}

complex operator- (const complex& z1, const complex& z2){
	complex diff = z1;
	diff -= z2;
	return diff;
}
complex operator- (const complex& z1, const double x){
	complex diff = z1;
	diff -= x;

	return diff;
}
complex operator- (const double x, const complex& z){
	complex diff(x);
	diff -= z;
	return diff;
}

complex operator* (const complex& z1, const complex& z2){
	complex prod(z1);

	prod *= z2;

	return prod;
}
complex operator* (const complex& z1, const double x){
	complex prod(z1);
	prod *= x;
	return prod;
}
complex operator* (const double x, const complex& z){
	complex prod(x);
	prod *= z;
	return prod;
}

complex operator/ (const complex& z1, const complex& z2){
	complex quot(z1);
	quot /= z2;
	return quot;
}
complex operator/ (const complex& z1, const double x){
	complex quot(z1);
	quot /= x;
	return quot;

}
complex operator/ (const double x, const complex& z){

	complex quot(x);

	quot /= z;
	

	return quot;
}

//unary functions
complex operator+ (const complex& z) {
	return z;
}
complex operator- (const complex& z) {
	return z / -1;
}

//other helper functions
double real(const complex& z) {
	return z.real();
}
double imag(const complex& z) {
	return z.imag();
}
double arg(const complex& z) {
	double x = z.real();
	double y = z.imag();

	if (x > 0 || y != 0) {
		return 2 * atan2(y , (sqrt(pow(x, 2) + pow(y, 2)) + x));
	}
	else if (x < 0 && y == 0) {
		return MY_MATH::PI;
	}
	else if(x == 0 && y == 0) {
		cout << "Undefined";
	}
}
double magnitude(const complex& z) {
	return z.magnitude();
}
double norm(const complex& z) {
	return pow(z.magnitude(), 2);
}

complex conj(const complex& z) {
	complex con(z.real(), z.imag() / -1);
	return con;
}
complex polar(const double r, const double theta) {
	double a = r * cos(theta);
	double b = r * sin(theta);

	return complex(a, b);
}
complex polar(const double r) {
	return complex(r, 0);
}
