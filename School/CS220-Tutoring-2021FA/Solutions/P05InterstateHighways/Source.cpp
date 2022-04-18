//P05InterstateHighways
#include <iostream>
using namespace std;

int main() {
    int highwayNumber;
    int primaryNumber;

    cout << " \n *** P05: Interstate Highways ***\n" << endl;

    cout << " Enter Highway Number (valid 1 through 999): ";
    cin >> highwayNumber;

    cout << endl;

    // Output whether the highway is auxiliary (serving which primary), or primary
    if ((highwayNumber < 1) || (highwayNumber > 999)) { // Invalid
        cout << " " << highwayNumber << " is not a valid interstate highway number." << endl;
    }
    else { // Valid
        if (highwayNumber > 99) {
            cout << " I-" << highwayNumber << " is auxiliary";
            // Get the primary
            primaryNumber = highwayNumber % 100; // Gets the rightmost 2 digits
            cout << ", serving I-" << primaryNumber;
        }
        else { // Must be 1-99
            primaryNumber = highwayNumber;
            cout << " I-" << primaryNumber << " is primary";
        }

        // Ready now to output the direction. 
        if ((primaryNumber % 2) == 0) { // Even
            cout << ", going east/west." << endl;
        }
        else { // Odd
            cout << ", going north/south." << endl;
        }
    }

    return 0;
}