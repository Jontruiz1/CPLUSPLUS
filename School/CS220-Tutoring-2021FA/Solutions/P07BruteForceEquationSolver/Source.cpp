// P07BruteForceEquationSolver
#include <iostream>
using namespace std;

int main() {
	int a1, b1, c1;
	int a2, b2, c2;
	int x, y;
	bool eqn1Soln;
	bool eqn2Soln;
	bool solutionFound;
	int xSolution, ySolution;

	cout << "*** Brute Force Equation Solver ***" << endl;

	cout << "Enter coefficients (a, b, c) for first equation separated by spaces: ";
	cin >> a1 >> b1 >> c1;

	cout << "Enter coefficients (a, b, c) for second equation separated by spaces: ";
	cin >> a2 >> b2 >> c2;

	solutionFound = false;

	for (x = -10; x <= 10 && !solutionFound; ++x) {
		for (y = -10; y <= 10 && !solutionFound; ++y) {
			//cout << x << " " << y << endl;
			eqn1Soln = ((a1 * x + b1 * y) == c1);
			eqn2Soln = ((a2 * x + b2 * y) == c2);
			if (eqn1Soln && eqn2Soln) {
				solutionFound = true;
				cout << "x = " << x << ", y = " << y << endl;
			}
		}
	}

	if (!solutionFound) {
		cout << "There is no solution" << endl;
	}

	return 0;
}
