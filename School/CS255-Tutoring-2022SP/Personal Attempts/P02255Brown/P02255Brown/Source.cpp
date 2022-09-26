#include <iostream>
#include "Vector.h"

using namespace std;

int main() {
	srand(time(NULL));
	CustomVector curr;
	curr.createVector(8);
	
	cout << "*** P02: Classes ***" << endl << endl;

	curr.addVector(13);
	curr.addVector(12);
	curr.addVector(11);
	curr.addVector(21);
	curr.addVector(12);
	curr.addVector(11);

	cout << "The vector currently stores " << curr.getSize() << " values" << endl;
	cout << "The vector can currently hold " << curr.getCapacity() << " values" << endl;
	cout << "The value at location 4 is: " << curr.getItem(4) << endl;

	curr.addVector(22);
	curr.addVector(54);
	curr.addVector(8);
	curr.addVector(9);

	cout << endl;
	cout << "The vector can currently hold " << curr.getCapacity() << " values" << endl;
	cout << "The vector currently stores " << curr.getSize() << " values" << endl;
	cout << "The value at location 10 is: " << curr.getItem(10) << endl;

	curr.getItem(20);

	curr.destroyVector();


}