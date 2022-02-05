// array demo
#include<iostream> 
#include<array> 
using namespace std;

int main()
{
	// Initializing the array elements 
	array<int, 6> ar1 = { 1, 2, 3, 4, 5, 6 };

	// Printing array elements using at() 
	cout << "ar1: elements (at()): ";
	for (int i = 0; i < 6; i++)
		cout << ar1.at(i) << " ";
	cout << endl;

	// Printing array elements using operator[] 
	cout << "\nar1: elements (operator[]): ";
	for (int i = 0; i < 6; i++)
		cout << ar1[i] << " ";
	cout << endl;

	// Printing first element of array 
	cout << "\nar1: first element " << ar1.front() << endl;

	// Printing last element of array 
	cout << "ar1: last element " << ar1.back() << endl;

	// Printing number of array elements 
	cout << "\nar1: number of elements " << ar1.size() << endl;

	// Printing maximum elements array can hold 
	cout << "ar1: max possible elements " << ar1.max_size() << endl;

	// Initializing 2nd array 
	array<int, 6> ar2 = { 7, 8, 9, 10, 11, 12 };

	// Printing 1st and 2nd array before swapping 
	cout << "\nar1: before swapping: ";
	for (int i = 0; i < 6; i++)
		cout << ar1[i] << " ";
	cout << endl;

	cout << "ar2: before swapping: ";
	for (int i = 0; i < 6; i++)
		cout << ar2[i] << " ";
	cout << endl;

	// Swapping ar1 values with ar2 
	ar1.swap(ar2);

	// Printing 1st and 2nd array after swapping 
	cout << "\nar1: after swapping: ";
	for (int i = 0; i < 6; i++)
		cout << ar1[i] << " ";
	cout << endl;

	cout << "ar2: after swapping: ";
	for (int i = 0; i < 6; i++)
		cout << ar2[i] << " ";
	cout << endl;

	// Filling array with 0 
	ar1.fill(0);

	// Displaying array after filling 
	cout << "\nar1: after fill(0): ";
	for (int i = 0; i < 6; i++)
		cout << ar1[i] << " ";
	cout << endl;

	// Declaring 3rd array 
	array<int, 0> ar3;

	// Checking size of array if it is empty 
	ar3.empty() ? cout << "\nar3: array empty" : cout << "\nar3: array not empty";
	cout << endl;

	return 0;
}
