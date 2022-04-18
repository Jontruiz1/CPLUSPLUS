#include <iostream>
#include <vector>

using namespace std;

int main() {
	int a, b, c;
	int a2, b2, c2;

	cout << "*** Brute Force Equation Solver ***" << endl;
	cout << "Enter coefficients (a, b, c) for first equation separated by spaces: ";
	cin >> a >> b >> c;
	cout << "Enter coefficients (a, b, c) for second equation separated by spaces: ";
	cin >> a2 >> b2 >> c2;

	for (int x = -10; x <= 10; ++x) {
		for (int y = -10; y <= 10; ++y) {
			if ((a * x + b * y == c) && (a2 * x + b2 * y == c2)) {
				cout << "x = " << x << ", y = " << y << endl;
				return 1;
			}
		}
	}
	cout << "There is no solution\n";
	return 0;

}