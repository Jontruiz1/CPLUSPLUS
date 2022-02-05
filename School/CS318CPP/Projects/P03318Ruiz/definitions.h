#ifndef DEFINITIONS_H
#define DEFINITIONS_H

#include "complex.h"
#include <iostream>
#include <cmath>
#include <assert.h>
#include <cmath>
#include <string>
#include <ostream>;

using namespace std;

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
complex& complex::operator+= (const complex& z) {
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
complex operator+ (const complex& z1, const double x) {
	complex sum(z1);
	sum += x;

	return sum;
}
complex operator+ (const double x, const complex& z) {
	complex sum(x);
	sum += z;

	return sum;
}

complex operator- (const complex& z1, const complex& z2) {
	complex diff = z1;
	diff -= z2;
	return diff;
}
complex operator- (const complex& z1, const double x) {
	complex diff = z1;
	diff -= x;

	return diff;
}
complex operator- (const double x, const complex& z) {
	complex diff(x);
	diff -= z;
	return diff;
}

complex operator* (const complex& z1, const complex& z2) {
	complex prod(z1);

	prod *= z2;

	return prod;
}
complex operator* (const complex& z1, const double x) {
	complex prod(z1);
	prod *= x;
	return prod;
}
complex operator* (const double x, const complex& z) {
	complex prod(x);
	prod *= z;
	return prod;
}

complex operator/ (const complex& z1, const complex& z2) {
	complex quot(z1);
	quot /= z2;
	return quot;
}
complex operator/ (const complex& z1, const double x) {
	complex quot(z1);
	quot /= x;
	return quot;

}
complex operator/ (const double x, const complex& z) {

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
		return 2 * atan2(y, (sqrt(pow(x, 2) + pow(y, 2)) + x));
	}
	else if (x < 0 && y == 0) {
		return MY_MATH::PI;
	}
	else if (x == 0 && y == 0) {
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

#endif