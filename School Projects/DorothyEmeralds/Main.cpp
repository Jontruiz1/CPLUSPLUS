#include <iostream>
#include <queue>
#include <time.h>

using namespace std;

int main() {
    //seeding
    srand(time(NULL));
    int baskets, minutes, count = 0, emeralds = 0;
    const int E = rand() % 100 + 1;

    cout << "**** Dorothy and Emeralds ****" << endl << endl;

    cout << "Enter the number of baskets: ";
    cin >> baskets;
    cout << endl;
    priority_queue<int> vect(baskets, E);

    cout << "Enter the number of minutes: ";
    cin >> minutes;
    cout << endl;

    for (int i = 0; i < minutes; i++) {

        //checks if theres any emeralds left in the current basket and if there aren't you break;
        if (vect[count] == 0) break;

        //adds emeralds in the current basket to total
        emeralds += vect[count];

        //sets current basket emerald to floor(current emeralds / 2)
        vect[count] = floor(vect[count] / 2);

        //if count == last basket, set count to 0 else add one to count
        count = count == (baskets - 1) ? 0 : count + 1;
    }

    cout << "Dorothy has gathered " << emeralds << " emeralds!";

}
