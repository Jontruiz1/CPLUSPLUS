#ifndef COMPLEX_H
#define COMPLEX_H
#include <iostream>
#include <cmath>
using namespace std;

class complex {

private:
    double re, im;

public:
/****************************************************************************************
Member Functions
****************************************************************************************/

    // Constructors
    complex() : re(0), im(0) {};

    complex(double a) : re(a), im(0) {}

    complex(double a, double b) : re(a), im(b) {}

    //Copy Constructor
    complex(const complex& z) : re(z.re), im(z.im) {}

    // Assignment Operator
    complex& operator=(const complex& rhs) {
        re = rhs.re;
        im = rhs.im;
        return *this;
    }

    // Complex Math Operations
    // Addition
    complex& operator+=(const complex& z) {
        re = re + z.re;
        im = im + z.im;
        return *this;
    }

    complex& operator+=(const double x) {
        re = re + x;
        return *this;
    }

    // Subtraction
    complex& operator-=(const complex& z) {
        re = re - z.re;
        im = im - z.im;
        return *this;
    }

    complex& operator-=(const double x) {
        re = re - x;
        return *this;
    }

    // Multiplication
    //     (a + b i) * (c + d i) = (ac ? bd) + (ad + bc)i
    complex& operator*=(const complex& z) {
        double tmp_re = (re * z.re) - (im * z.im);
        double tmp_im = (re * z.im) + (im * z.re);
        re = tmp_re;
        im = tmp_im;
        return *this;
    }

    complex& operator*=(const double x) {
        re = re * x;
        im = im * x;
        return *this;
    }

    // Division
    complex& operator/=(const complex& z) {
        double tmp_re = ((re * z.re) + (im * z.im)) / z.magnitude();
        double tmp_im = ((im * z.re) - (re * z.im)) / z.magnitude();
        re = tmp_re;
        im = tmp_im;
        return *this;
    }

    complex& operator/=(const double x) {
        re = re / x;
        im = im / x;
        return *this;
    }

    // Accessors
    double real() const { return re; }
    double imag() const { return im; }
    double magnitude() const { return sqrt(re * re + im * im); }

}; // end complex class


/****************************************************************************************
Helper and Non-member (Free) Functions
****************************************************************************************/
////////////////////////////////////////
// Binary Arithmetic Helper Functions //
////////////////////////////////////////

// Addition
complex operator+(const complex& z1, const complex& z2) {
    return (complex(z1) += z2);
}

complex operator+(const complex& z1, const double x) {
    return (complex(z1) += x);
}

complex operator+(const double x, const complex& z1) {
    return (complex(x) += z1);
}

//Subtraction
complex operator-(const complex& z1, const complex& z2) {
    return (complex(z1) -= z2);
}

complex operator-(const complex& z1, const double x) {
    return (complex(z1) -= x);
}

complex operator-(const double x, const complex& z1) {
    return (complex(x) -= z1);
}

//Multiplication
complex operator*(const complex& z1, const complex& z2) {
    return (complex(z1) *= z2);
}

complex operator*(const complex& z1, const double x) {
    return (complex(z1) *= x);
}

complex operator*(const double x, const complex& z1) {
    return (complex(x) *= z1);
}

// Division
complex operator/(const complex& z1, const complex& z2) {
    return (complex(z1) /= z2);
}

complex operator/(const complex& z1, const double x) {
    return (complex(z1) /= x);
}

complex operator/(const double x, const complex& z1) {
    return (complex(x) /= z1);
}

///////////////////////////////////////
// Unary Arithmetic Helper Functions //
///////////////////////////////////////
complex operator+(const complex& z) { return (complex(z) *= 1); }

complex operator-(const complex& z) { return (complex(z) *= -1); }


/////////////////////////////////
// Comparison Helper Functions //
/////////////////////////////////
bool operator==(const complex& z1, const complex& z2) {
    return ((z1.real() == z2.real()) && (z1.imag() == z2.imag()));
}

bool operator!=(const complex& z1, complex& z2) {
    return (!(z1.real() == z2.real()) || !(z1.imag() == z2.imag()));
}


///////////////////////////////////
// Input/Output Helper Functions //
///////////////////////////////////

istream& operator>>(istream& in, complex& z) {
    //**************** TO BE COMPLETED *********************

    double x;
    double y;
    char separator;
    in >> separator >> x >> separator >> y >> separator;
    z = complex(x, y);
    return in;
}

ostream& operator<<(ostream& out, const complex& z) {
    out << "(" << z.real() << ", " << z.imag() << ")";
    return out;
}


////////////////////////////
// Other Helper Functions //
////////////////////////////

double magnitude(const complex& z) { return z.magnitude(); }
double real(const complex& z) { return z.real(); }
double imag(const complex& z) { return z.imag(); }

// Conjugate: conjugate of a + bi is a - bi
complex conj(const complex& z) {
    return complex(z.real(), -(z.imag()));
}

// Norm: Squared magnitude (absolute) value of  z
double norm(const complex& z) {
    double x = magnitude(z);
    return (x * x);
}

///////////////////////////////////
// Polar Coordinate Functions    //
///////////////////////////////////

// Polar:  Constructs a complex via polar coords.
complex polar(const double r, const double theta) {
    double re = r * cos(theta);
    double im = r * sin(theta);
    return complex(re, im);
}

complex polar(const double r) {
    return complex(r);
}

// Arg(Theta)
double arg(const complex& z) {
    double result = atan2(z.imag(), z.real());
    return result;
}

#endif

