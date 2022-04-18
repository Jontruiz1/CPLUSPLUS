//P04AirfareCalculator
#include <iostream>
using namespace std;

int main() {
    int passengerAge;
    int carryOns;
    int checkedBags;
    int airFare;

    cout << " *** P04: Airfare Calculator ***\n" << endl;

    cout << " Passenger age: ";
    cin >> passengerAge;
    cout << " Number of carryons: ";
    cin >> carryOns;
    cout << " Number of checked bags: ";
    cin >> checkedBags;

    if (passengerAge >= 60) {
        airFare = 290; // Senior
    }
    else if (passengerAge <= 2) {
        airFare = 0; // Lap child
    }
    else {    // Regular: 2 < age < 60
        airFare = 300;
    }

    if (carryOns > 0) {
        airFare += 10;
    }

    if (checkedBags >= 2) {
        airFare += 25 + (checkedBags - 2) * 50;
    }
    // Note: 0 or 1 bags is $0, so no adjustment to airfare

    cout << endl;
    cout << " Airfare: $" << airFare << endl;

    return 0;
}

/* NOTES

* Notice the careful use of distinct if-else statements. Each has a particular role.

* Updating a single value (airFare) is a common pattern. An alternative approach uses variables for baseCost, carryOnCost,
  and checkedBagCost. Each if-else assigns one of those variables. Then a final equation assigns
  airFare = baseCost + carryOnCost + checkedBagCost

*/