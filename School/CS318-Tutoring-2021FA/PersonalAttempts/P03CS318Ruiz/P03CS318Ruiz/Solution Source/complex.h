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
Member Functions: The following member functions must also be provided with the following
                    return types and signatures:
*****************************************************************************************
    Constructors:
        complex () // default constructor that should initialize to (0,0).
        complex (double a) // constructor and also used for double-to-complex conversion
        complex (double a, double b) // constructor of Cartesian coordinate representation


    Copy Constructor:  The default can be used since the members are double and the copy 
                        semantics for double are what we want for the implementation of 
                        complex numbers. However, here is what the signature should be.
                        Even though the default copy constructor is provided and will work 
                        the way we intend, you should explicitly write it for this project.
        complex( const complex& c) // copy constructor.

    Assignment operation (=): copy values from rhs object and also return reference to 
                                current object
        complex& operator=(const complex & rhs)


    Complex member arithmetic and additional assignment operators +=, -=, *=,  /=
        like the assignment operator (“=”) return reference to current object.
        Write complex& operator op(const complex& z) // where op is: +=, -=, *=, /=
        Write complex& operator op(const double z) // where op is: +=, -=, *=, /=

        complex& operator+=(const complex& z)
        complex& operator+=(const double x)

    Accessors:
        double real() const
        double imag() const
        double magnitude() const //also known as absolute value of a complex number
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
    //      (a + bi)/(c + di)
    //      ((ac+bd)/norm(c+di)), ((bc-ad)/norm(c+di))i) <== complex result
    //      norm(c+di) ==> ((c*c) + (d*d))
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
    The following helper and non-member (free) functions should also be part of the 
    complex part of complex.h and/or complex.cpp, whatever is appropriate. 
    Note that +, -, *, and / are not to be friend functions.
    Hint: Use +=, -=, *=, and /= to implement the respective binary complex 
            arithmetic operators.
*****************************************************************************************
    Binary Arithmetic Helper Functions:
        complex operator+(const complex& z1, const complex& z2);
        complex operator+(const complex& z1, const double x);
        complex operator+(const double x, const complex& z);

        Note: Similarly, do the same for operator op‘s three signatures and
                    return types where op = -, *, and /.

    Unary Arithmetic Helper Functions:
        complex operator+(const complex& z);
        complex operator- (const complex& z);

    Comparison Helper Functions:
        bool operator= = (const complex& z1, const complex& z2);
        bool operator!=  (const complex& z1, complex& z2);
                    
        Note: the lack of ordering operators, e.g. operator<.

    Input/Output Helper Functions:
        >>: Input and parse complex literals of form: (a, b) where a and b 
            are both read as type double literals.
            Note: You must read past and ignore the comma, 
                    and parentheses: ‘,’, ‘(‘ and ‘)’.

        istream& operator>>(istream&, complex&); 

        <<: Output the complex number in the form: (a,  b). Do not forget to insert 
            a comma character between values a and b and matching parentheses around

        ostream& operator<<(ostream&, const complex&);

    Other Helper Functions: These are free functions and not member functions. 
            Also refer to meaning of these functions by referring to the 
            above-mentioned Websites.

        double magnitude(const complex& z); // also known as absolute value
        double real(const complex& z);
        double imag(const complex& z);

        complex conj(const complex& z); // Returns the conjugate
        double norm(const complex& z); // Returns squared magnitude (absolute) value
        
        // Constructs a complex via polar coords.
                polar = r * (cos(theta) + (i*sin(theta)))
                magnitude(z)
                re = r*cos(theta)    im = r*sin(theta)
                theta in radians
        
        complex polar(const double r, const double theta); 
        complex polar(const double r);
        
        // arg (theta) value of complex number, z.
             Note:  Must be calculated from internal representation. 
             Undefined for z = 0. 
             Use atan2( ) function from  <cmath> to implement this arg() function.
        
        double arg(const complex& z);             

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

// Conjugate:  conjugate of a + bi is a - bi
complex conj(const complex& z) { 
    return complex(z.real(), -(z.imag()));
}

// Norm: Squared  magnitude (absolute) value of  z
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

// Arg(Theta): Returns arg (theta) value of complex number, z
//              result in radians arctan2(im, re)
double arg(const complex& z) {
    double result = atan2(z.imag(), z.real());
    return result;
}

#endif

