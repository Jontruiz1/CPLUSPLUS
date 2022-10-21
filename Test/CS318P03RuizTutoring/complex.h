#include <iostream>

using namespace std;
class complex {
public:
	complex();
	complex(double a);
	complex(double a, double b);
	complex(const complex& c);

	complex& operator=(const complex& rhs);
	complex& operator+=(const complex& z);
	complex& operator-=(const complex& z);
	complex& operator*=(const complex& z);
	complex& operator/=(const complex& z);

	complex& operator+=(const double z);
	complex& operator-=(const double z);
	complex& operator*=(const double z);
	complex& operator/=(const double z);

	double real() const {
		return re;
	}
	double imag() {
		return im;
	}
	double magnitude() const;
private:
	 
	double re, im;
};

complex operator+(const complex& z1, const complex& z2) {

}
complex operator+(const complex& z1, const double x);

istream& operator>>(istream& in, complex rhs) {
	
	char garb;
	double a;
	double b;
	in >> garb >> a >> garb >> b >> garb;
	rhs = complex(a, b);
	return in;
}

