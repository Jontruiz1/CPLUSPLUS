// P01RandomWalksDriver
//	This program produces number random walks, each with number of points.
//	Distance for each walk is tracked.
//	Shortest, median, and longest distance walks are displayed

#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm> 
#include "Walk.h"
using namespace std;

int main() {
	int numWalks = 0; //number of random walks
	int numPoints = 0;
	vector<Walk> walks;

	cout << "*** Random Walks ***" << endl;

	cout << "\nThis program generates a number of random walks." << endl;

	cout << "\nEnter number of points for each walk: ";
	cin >> numPoints;

	cout << "\nEnter number of random walks to generate: ";
	cin >> numWalks;
	cout << endl;

	initRandom();

	for (int j = 0; j < numWalks; j++) {
		Walk currWalk;
		cout << endl;

		for (int i = 0; i < numPoints; i++) {
			currWalk.walkAgain();
			cout << "Walk/Step: " << j + 1 << "/" << i + 1 << ": ";
			cout << currWalk;
		}

		walks.push_back(currWalk);
	}

	// Use sort algorithm with lambda expression
	sort(walks.begin(), walks.end(), [](const Walk& lhs, const Walk& rhs) {
		return lhs.getDistance() < rhs.getDistance();
		});

	cout << "\nWalks Sorted: " << endl;
	double totalDistance = 0.0;
	for (auto w : walks) {
		cout << "\t" << w;
		totalDistance += w.getDistance();
	}


	// Display distance results
	int size = walks.size();
	cout << "\nAverage Distance: " << totalDistance / size << endl;
	cout << "\nShortest Distance/Walk: " << walks.at(0).getDistance() << endl;

	if (size % 2)
		cout << "Median Distance/Walk: " << walks.at(size / 2).getDistance() << endl;
	else
		cout << "Median Distance/Walk: "
		<< (walks.at(size / 2).getDistance() + walks.at((size / 2) - 1).getDistance()) / 2 << endl;

	cout << "Longest Distance/Walk: " << walks.at(size - 1).getDistance() << endl;
}