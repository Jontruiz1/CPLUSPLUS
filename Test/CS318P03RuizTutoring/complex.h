#include <iostream>

using namespace std;
class complex {
public:
	complex();
	complex(double a);
	complex(double a, double b);
	complex(const complex& c);

	complex& operator=(const complex& rhs);
	complex& operator+=(const complex& z){

		this->real();
		this->imag(); 

	};
	complex& operator-=(const complex& z);
	complex& operator*=(const complex& z);
	complex& operator/=(const complex& z);

	complex& operator+=(const double z);
	complex& operator-=(const double z);
	complex& operator*=(const double z);
	complex& operator/=(const double z);

	double real() const ;
	double imag() {
		return im;
	}
	double magnitude() const;

private:
	 
	double re, im;
};

complex operator+(const complex& z1, const complex& z2);
complex operator+(const complex& z1, const double x);

complex operator+(const complex& z) {
	return z;
}
complex operator-(const complex& z) {

}

