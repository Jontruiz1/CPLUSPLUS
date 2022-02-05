#ifndef COMPLEX_H
#define COMPLEX_H

#include <iostream>

using namespace std;

class complex {
private:
	double re, im;
public:
	//constructors
	complex();
	complex(double a);
	complex(double a, double b);
	complex(const complex& c);

	//returns reference to current object 
	complex& operator= (const complex& rhs);
	complex& operator+= (const complex& z);
	complex& operator-= (const complex& z);
	complex& operator*= (const complex& z);
	complex& operator/= (const complex& z);

	// conversions, returns references to current object
	complex& operator+= (const double x);
	complex& operator-= (const double x);
	complex& operator*= (const double x);
	complex& operator/= (const double x);

	//accessors
	double real() const;
	double imag() const;
	double magnitude() const;
};

//comparison helper functions
bool operator== (const complex& z1, const complex& z2);
bool operator!= (const complex& z1, complex& z2);

 //i/o helper functions
istream& operator>> (istream& i, complex& z);
ostream& operator<< (ostream& o, const complex& z);

//binary arithmetic helper functions
complex operator+ (const complex& z1, const complex& z2);
complex operator+ (const complex& z1, const double x);
complex operator+ (const double x, const complex& z);

complex operator- (const complex& z1, const complex& z2);
complex operator- (const complex& z1, const double x);
complex operator- (const double x, const complex& z);

complex operator*(const complex& z1, const complex& z2);
complex operator*(const complex& z1, const double x);
complex operator*(const double x, const complex& z);

complex operator/ (const complex& z1, const complex& z2);
complex operator/ (const complex& z1, const double x);
complex operator/ (const double x, const complex& z);

//unary helper functions
complex operator+ (const complex& z);
complex operator- (const complex& z);

//other helper functions
double real(const complex& z);
double imag(const complex& z);
double arg(const complex& z);
double magnitude(const complex& z);
double norm(const complex& z);

complex conj(const complex& z);
complex polar(const double r, const double theta);
complex polar(const double r);

#endif