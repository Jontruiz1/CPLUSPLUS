#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

#include "Walk.h"

using namespace std;


int main() {

	vector<Walk> walks;
	int points;
	int steps;
	double avg = 0;

	cout << "*** Random Walks ***" << endl;

	cout << "The program generates a nubmer of random walks."<<endl;
	cout << "Enter number of points for each walk: ";
	cin >> points;

	cout << "Enter number of random walks to generate: ";
	cin >> steps;

	for (int i = 0; i < steps; ++i) {
		Walk currWalk;
		for (int j = 0; j < points; ++j) {
			currWalk.walk();
			cout << "Walk/Step: " << i+1 << "/" << j+1 << ": Point: " << currWalk.getX() << ", " << currWalk.getY() << " Distance: " << currWalk.getDist() << endl;
		}
		walks.push_back(currWalk);
		cout << endl;
	}

	sort(walks.begin(), walks.end(), [](Walk& lhs, Walk& rhs) {
		return lhs.getDist() < rhs.getDist();
		});

	cout << "Walks Sorted: ";

	for (Walk i : walks) {
		cout << "Point: "<<  i.getX() << " " << i.getY() << " Distance: " << i.getDist() << endl;
		avg += i.getDist();
	}
	avg /= points;


	cout << "Average Distance: " << avg;
	cout << "Shortest Distance/Walk: " << walks[0].getDist();
	cout << "Median Distance/Walk: ";
	cout << "Longest Distance/Walk: " << walks[points].getDist();

}