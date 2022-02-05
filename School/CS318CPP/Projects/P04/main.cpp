#include <iostream>
#include <queue>
#include <time.h>

using namespace std;

int main() {
    //seeding
    srand(time(NULL));
    int size, minutes, temp, emeralds = 0;
    priority_queue<int> baskets;

    cout << "**** Dorothy and Emeralds ****" << endl << endl;

    cout << "Enter the number of baskets: ";
    cin >> size;
    cout << endl;

    cout << "Enter the number of minutes: ";
    cin >> minutes;
    cout << endl;

    //generate random numbers to put in baskets
    for (int i = 0; i < size; i++) {
        baskets.push(rand() % 100 + 1);
    }

    //loop based on minutes
    for (int i = 0; i < minutes; i++) {
        //if the greatest is 0, theres no more emeralds to add so you can break
        if (baskets.top() == 0) break;
        temp = baskets.top();
        emeralds += temp;
        baskets.pop();
        baskets.push(floor(temp / 2));
    }

    cout << endl;

    cout << "Dorothy has gathered " << emeralds << " emeralds!";
}
