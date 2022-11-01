// HW02_Lambdas.cpp
//
// PUT YOUR NAME HERE
#include <algorithm>
#include <vector>
#include <iostream>
#include "Box.h"
using namespace std;

int main()
{
    // Create a vector of at least four boxes
	vector<Box> boxes = { Box(3, 2, 4), Box(1, 4, 7), Box(7, 2, 3), Box(3, 5, 4) };

    // Using "sort" and a lambda sort the boxes in ascending order of volume
    // Display the boxes
	sort(boxes.begin(), boxes.end(), [](const Box& a, const Box& b) {
		return a.getVolume() < b.getVolume();
		});
	for (const Box& a : boxes) {
		cout << a << endl;
	}
	cout << endl;
	// Create a lambda that can be used to sort boxes in descending order of volume
	//	Assign the lambda to a variable
	auto sorter = [](const Box& a, const Box& b) {
		return a.getVolume() > b.getVolume();
	};

	// Using "sort" and the lambda variable just created sort the boxes
	// Display the boxes
	sort(boxes.begin(), boxes.end(), sorter);
	for (const Box& a : boxes) {
		cout << a << endl;
	}

	// Using "transform" and a lambda double the height of each box in the vector
	// Display the boxes
	cout << endl;

	transform(boxes.begin(), boxes.end(), boxes.begin(), [](Box& a) {
		return Box(a.getLength(), a.getWidth(), a.getHeight() * 2); });

	for (const Box& a : boxes) {
		cout << a << endl;
	}
	// Using "count_if" ... count the number of boxes with volume greater than 50
	// Display the count from count_if
	int count = count_if(boxes.begin(), boxes.end(), [](const Box& a) {
		return a.getVolume() > 50;
		});
	cout << count;
    cout << endl;
    return 0;
}
