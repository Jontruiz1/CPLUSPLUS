#include <iostream>

using namespace std;


int main() {
	int age;
	int carryOn;
	int checkedBags;
	int airFare;

	cout << "*** P04: Airface Calculator ***";

	cout << "Passenger age: ";
	cin >> age;
	cout << "Number of carryons: ";
	cin >> carryOn;
	cout << "Number of checked bags: ";
	cin >> checkedBags;


	if (age >= 60) {
		airFare = 290;
	}
	else if (age <= 2) {
		airFare = 0;
	}
	else {
		airFare = 300;
	}

	if (carryOn) {
		airFare += carryOn * 10;
	}



	cout << "Airfare: ";



}