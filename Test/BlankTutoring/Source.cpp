#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Complex {
private:
	double real;
	double im;
public:
	void operator+= (Complex& rhs) {
		this->real += rhs.im;
		this->im += rhs.im;
	
	}

	Complex() {
		this->real = 1;
		this->im = 1;
	}

	Complex(double a, double b) {
		this->real = a;
		this->im = b;
	}
};

int main() {
	int x = 5;
	int y = 2;
	int tester = x += y;
	cout << tester;



	Complex first(5, 4);
	Complex second(3, 2);
}