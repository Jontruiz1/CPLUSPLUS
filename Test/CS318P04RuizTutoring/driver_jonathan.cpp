#include <iostream>
#include <queue>

using namespace std;

int main() {
	srand(time(NULL));
	int emeralds = rand() % (100 - 50 + 1) + 50;
	int nBaskets, minutes, total = 0;
	priority_queue<int> baskets;

	cout << "**** Dorothy and Emeralds ****\n\n";
	cout << "Enter the number of baskets: ";
	cin >> nBaskets;
	for (int i = 0; i < nBaskets; ++i) { baskets.push(emeralds); }
	cout << endl;
	
	cout << "Enter the number of minutes: ";
	cin >> minutes;
	cout << endl;

	for (int i = 0; i < minutes && !baskets.empty(); ++i) {
		int curr = baskets.top();
		total += curr;
		baskets.pop();
		baskets.push(floor(curr / 2));
	}

	cout << "Dorothy has gathered " <<  total << " emeralds!";

}