//P04DorothyAndEmeralds
// Note that by default C++ creates a max-heap for priority queue 
#include <iostream> 
#include <ctime>
#include <queue> 

using namespace std;

int main()
{
    priority_queue <int> emeralds;
    int baskets;
    int minutes;

    cout << " **** Dorothy and Emeralds ****" << endl;
    cout << "\n Enter the number of baskets: ";
    cin >> baskets;

    cout << "\n Enter the number of minutes: ";
    cin >> minutes;

    int count;
    //cout << "\n Emeralds put in baskets: ";

    srand(time(NULL)); //generates random seed val
    for (int i = 0; i < baskets; i++) {
        count = rand() % ((100 - 1) + 1);
        emeralds.push(count);
        //cout << count << "  ";
    }
    //cout << endl;

    int totalEmeralds = 0;
    int e;
    //cout << "\n";
    for (int i = 0; i < minutes; i++) {
        e = emeralds.top();
        totalEmeralds += e;
        emeralds.pop();
        emeralds.push(e / 2);
        //cout << "\tEmeralds popped / pushed: " << e << " " << e/2 << endl;
    }

    cout << "\n Dorothy has gathered " << totalEmeralds << " emeralds!\n";

    return 0;
}