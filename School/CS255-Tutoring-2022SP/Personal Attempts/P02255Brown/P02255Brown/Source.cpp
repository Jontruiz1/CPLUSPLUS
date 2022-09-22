#include <iostream>
#include "Vector.h"

using namespace std;

int main() {

	CustomVector<int> firstVect(8);

	cout << "*** P02: Classes ***" << endl << endl;

	firstVect.pushToBack(10);
	firstVect.pushToBack(15);
	firstVect.pushToBack(5);
	firstVect.pushToBack(9);
	firstVect.pushToBack(21);
	firstVect.pushToBack(6);
	cout << "The vector currently stores " << firstVect.getSize() << " values" << endl;

	firstVect.pushToBack(20);
	firstVect.pushToBack(2);

	cout << "The vector currently stores " << firstVect.getSize() << " values" << endl;
	cout << "The vector can currently hold " << firstVect.getCapacity() << " values" << endl;

	cout << "The value at location 4 is: " << firstVect.getElement(4) << endl;
}