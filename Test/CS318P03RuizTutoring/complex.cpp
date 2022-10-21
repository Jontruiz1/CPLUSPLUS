#include "complex_jonathan.h"


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

complex& complex::operator*=(const complex& z) {
	
	
	return *this;
}

complex operator*(const complex& z1, const complex& z2) {
	// what if we made a complex nunmber
	// thats a copy of z1
	// then did *= on the copy
	// return copy


}
