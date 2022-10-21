
#include <cmath>
#include <iostream>

using namespace std;

class complex {

private:
	// real number
	double re;
	//imaginary number
	double im;

public:
	// default constructor that should initialize to (0,0).
	complex() {
		re = 0;
		im = 0;
	}
	// constructor used for double-to-complex conversion
	complex(double a) {
		re = a;
	}
	// constructor of Cartesian coordinate representation
	complex(double a, double b) {
		re = a;
		im = b;
	}

	// Copy Constructor
	complex(const complex& c) {
		re = c.re;
		im = c.im;
	}
	
	// Assignment operation(= )
	// copy values from rhs object and return reference to current object
	complex& operator=(const complex& rhs) {
		re = rhs.re;
		im = rhs.im;
		return *this;
	}

	// Class complex member arithmetic and additional assignment operators +=, -=, *=, /= 

	complex& operator+=(const complex& z) {
		re = re + z.re;
		im = im + z.im;
		return *this; // returning refrence to the object. 
	}
	complex& operator -=(const complex& z) {
		re = re - z.re;
		im = im - z.im;
		return *this;
	}
	complex& operator *=(const complex& z) {
		re = re * z.re;
		im = im * z.im;
		return *this;
	}
	complex& operator /=(const complex& z) {
		re = re / z.re;
		im = im / z.im;
		return *this;
	}
	// for use of conversions -- CONST DOUBLE 
	complex& operator +=(const double x) {
		re = re + x;
		return *this; // like the assignment operator (“=”)
					  // returns reference to current object
	}
	complex& operator -=(const double z) {
		re = re - z;
		return *this;
	};
	complex& operator *=(const double z) {
		re = re * z;
		return *this;
	};
	complex& operator /=(const double z) {
		re = re / z;
		return *this;
	};
//Accessors
	double real() const {return re;}
	double imag() const {return im;};
	double magnitude() const{ return sqrt((re * re) + (im * im));}; 
	// magnitude is also known as absolute value of a complex number
	
};

//////////			END OF CLASS			//////////



//////////		Other Helper Functions		//////////
 

//Note: These are free functions and not member functions.
//Also refer to meaning of these functions by referring to the above - mentioned Websites.

double magnitude(const complex& z) {
	return abs(z.magnitude()); // also known as absolute value
}

double real(const complex& z) {
	return z.real();
}

double imag(const complex& z) {
	return z.imag();
}

// Returns arg (theta) value of complex number, z. 
double arg(const complex& z) {

	if (z.real() == 0 && z.imag() == 0) {

		double zero = 0;
		return zero;
	}
	if (z.real() < 0 && z.imag() == 0) {

		double pie = 3.14;
		return pie;
	}
	if (z.imag() != 0 || z.real() > 0) {

		double theta = atan2(z.real(), z.imag());

		return theta;

	}
}

// Constructs a complex via polar coords.
complex polar(const double r, const double theta) {

	double rr = sqrt(pow(cos(theta), 2) + pow(sin(theta), 2));

	return complex(rr, arg(theta));

}

complex polar(const double r) {

	return complex(r, 0);

}
// Returns the conjugate of complex number
complex conj(const complex& z) {

	double rossi = pow(z.real(), 2) + pow(z.imag(), 2);

	return rossi;
}

double norm(const complex& z) {

	return abs(pow(z.magnitude(), 2));
}

//Note: Must be calculated from internal representation.Undefined for z = 0. 
//Use atan2() function from <cmath> to implement this arg() function. */


//Hint : Use +=, -=, *=, and /= to implement the respective binary complex arithmetic operators.


//////////		Binary Arithmetic Helper Functions		//////////

//Adding two complex objects
complex operator + (const complex& z1, const complex& z2) { return (complex(z1) += z2); }
//Subtracting two complex objects
complex operator - (const complex& z1, const complex& z2) {return (complex(z1) -= z2);}
//Multiplying two complex objects 
complex operator * (const complex& z1, const complex& z2) {

	complex z3((z1.real() * z2.real()) - (z1.imag() * z2.imag()),
		((z1.real() * z2.imag()) + z1.imag() * z2.real()));

	return z3;
}

//Dividing two complex objects

complex operator / (const complex& z1, const complex& z2) {

	double re = (((z2.real() * z1.real())) + (((z2.imag() * z1.real())))
		/ ((pow(z1.real(), 2)) + ((pow(z1.imag(), 2)))));

	double im = (((z2.imag() * z1.real())) - (((z2.real() * z1.imag())))
		/ ((pow(z1.real(), 2)) + ((pow(z1.imag(), 2)))));

	complex z3(re, im);


	return z3;
}

//Adding a double to a complex number
complex operator + (const complex& z1, const double x) {return (complex(z1) += x);}

//Substacting a double from a complex object 
complex operator - (const complex& z1, const double x) {return (complex(z1) -= x);}

//Multiplying a double and a complex number
complex operator * (const complex& z1, const double x) {

	complex z3(z1.real() * x, z1.imag() * x);
	return z3;
}

//Dividing a complex number by a double
complex operator / (const complex& z1, const double x) {

	complex z3(z1.real() / x, z1.imag() / x);
	return z3;
}


//adding a complex number to a double  
complex operator + (const double x, const complex& z) {
	complex z3 = (x + z.real(), z.imag());
	return z3;
}

//Subtracting a complex object from a double 
complex operator - (const double x, const complex& z) {
	complex z3 = (x - z.real(), z.imag());
	return z3;
}

//Multiplying a complex object to a double
complex operator * (const double x, const complex& z) {
	complex z3(z.real() * x, z.imag() * x);
	return z3;
};

//Dividing a doube by a complex object
complex operator / (const double x, const complex& z) {
	complex z3(x / z.real(), x / z.imag());
	return z3;
}

//////////		Unary Arithmetic Helper Functions		//////////

complex operator + (const complex& z) {return (complex(z) * 1);}

complex operator - (const complex& z) {return (complex(z) *= -1);}


//////////		Comparison Helper Functionns		//////////

bool operator == (const complex& z1, const complex& z2) {

	double realone = z1.real();
	double realtwo = z2.real();

	double imagone = z2.imag();
	double imagtwo = z2.imag();

	if (realone == realtwo && imagone == imagtwo) {

		return true;

	}
	else { return false; }

}

bool operator!=(const complex& z1, complex& z2) {

	double realone = z1.real();
	double realtwo = z2.real();

	double imagone = z2.imag();
	double imagtwo = z2.imag();

	if (realone == realtwo || imagone == imagtwo) {

		return false;

	}
	else { return true; }

}

istream& operator>>(istream& in, complex& c) {

	double x, y;
	char garb;
	
	in >> garb >> x >> garb >> y >> garb;
	c = complex(x, y);
	return in;

}

ostream& operator<<(ostream& out, const complex& c) {

	out << "(" << c.real() << "," << c.imag() << ")";

	return out;
}

// Output the complex number in the form: (a, b) Note:
//Do not forget to insert a comma character between values a and b and matching parentheses around
