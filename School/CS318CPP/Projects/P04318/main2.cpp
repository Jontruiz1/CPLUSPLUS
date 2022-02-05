#include <iostream>
#include <vector>

using namespace std;

int main() {

    cout << "*** Dorothy and Emeralds ***\n\n";

    // get info:
    int baskNum = 0;
    cout << "Enter number of baskets: ";
    cin >> baskNum;

    int minutes = 0;
    cout << "\nEnter number of minutes: ";
    cin >> minutes;

    // num of emeralds:
    int emeralds = 89;

    // setup the baskets:
    vector<int> baskets(baskNum, emeralds);

    // Dorothy's emeralds:
    int dorothysEms = 0;

    int min = 0;
    // while there are still baskets:
    for (int i = 0; i < baskets.size(); i++) {
        // while there's still time:
        if (min < minutes) {
            // add emeralds:
            dorothysEms += baskets[i];
            // refill baskets:
            baskets[i] = floor(emeralds / 2);
            // increase time elapsed:
            min++;

            // if there's still time, then go through the baskets again:
            if (i == baskets.size() - 1 && min < minutes) {
                i = 0;
            }
        }
    }

    // display results:
    cout << "\nDorothy has gathered " << dorothysEms << " emeralds!\n";

    return 0;
}