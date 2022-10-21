#include "complex.h"

complex::complex() {
	re = 0;
	im = 0;
}

complex::complex(double a) {
	re = a;
	im = 0;
}

complex::complex(double a, double b) {
	re = a;
	im = b;
}

complex& complex::operator=(const complex& rhs) {

}
complex& complex::operator+=(const complex& z) {

}
complex& complex::operator-=(const complex& z){
}
complex& complex::operator*=(const complex& z) {

}
complex& complex::operator/=(const complex& z) {

}

complex& complex::operator+=(const double z) {

}
complex& complex::operator-=(const double z) {

}
complex& complex::operator*=(const double z);
complex& complex::operator/=(const double z);