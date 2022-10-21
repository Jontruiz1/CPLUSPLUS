#include <iostream>

using namespace std;

int main() {
	
	long long a = 0;
	long long b = 1;
	long long c;

	while (true) {
		cout << a << endl; 
		c = a;
		a = b;
		b = c + b;
		
	}
}