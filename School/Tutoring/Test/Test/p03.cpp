#include <iostream>
#include "Problem.h"
using namespace std;

int main() {
	int carCount, holdingCount;
	Problem myProblem;

	cout << "Enter number of cars: ";
	cin >> carCount;
	cout << "Enter number of holding tracks: ";
	cin >> holdingCount;

	myProblem.generate(carCount, holdingCount);
	myProblem.solve();

	// Prints the results of the full solution, if solvable
	if (myProblem.isSolvable == true) {
		for (int i = 0; i < myProblem.resultsVect.size(); ++i) { cout << myProblem.resultsVect.at(i); }
	}
	else { cout << "\nNo solution."; }

	cout << endl;
	myProblem.testVects();
	return 0;
}