/*
Jonathan Ruiz
Complex Numbers
*/

#include "complex.h"
#include "definitions.h";

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
