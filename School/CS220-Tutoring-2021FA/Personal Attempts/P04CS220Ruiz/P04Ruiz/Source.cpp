#include <iostream>
#include <queue>

using namespace std;


int main() {

	srand(time(NULL));
	priority_queue<int> emerald_holder;
	int baskets;
	int minutes;
	int emeralds = 0;

	/*
	int highway_number;

	cout << "*** P05: Interstate Highways ***";
	cout << "Enter Highway Number (valid 1 through 999): ";
	cin >> highway_number;

	
	//else if statement, check if the number is between 1 to 99, inclusive
	//inside the else if, we need to check if the highway_number is odd print out going north/south
	//need to check if the highway_number is even, print out going east/west

	//else if, checks if the number is between 100 to 999, inclusive
	//check the last 2 digits of the auxiliary highway, that tells us the primary highway
	//that hte auxiliary highway is servicing, finally use the primary highway number
	//determine if it runs north/south or east/west

	if (highway_number < 1 || highway_number > 999) {
		cout << highway_number << " is not a valid interstate highway number.";
	}
	else if (highway_number < 99) {

		//check if the number is even
		//	if even, print out going east/west
		//check if the number is odd
		//  if odd, print out going north/south
	}
	else {
		//check the last 2 digits of the number
		//this gives us primary highway number
	}
	*/
	
	cout << "Enter the number of baskets: ";
	cin >> baskets;

	cout << "Enter the number of mintes: ";
	cin >> minutes;

	for (int i = 0; i < baskets; i++) {
		emeralds = rand() % 100 + 1;
		emerald_holder.push(emeralds);
	}
	


	// for loop based on the number of minutes
	// adds the emeralds into emeralds using top()
	// emptying each basket, pop the priority queue
	// push floor(E/2) back into the queue

	cout << "Dorothy has gathered " << emeralds << " emeralds!";



}