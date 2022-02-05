#include "Header.h"
#include <iostream>
#include <iomanip>

using namespace std;

int main() {
	
	



}

complex& complex::operator*= (const double z) {
	this->re *= z;
	this->im *= z;
	
	return *this;

}