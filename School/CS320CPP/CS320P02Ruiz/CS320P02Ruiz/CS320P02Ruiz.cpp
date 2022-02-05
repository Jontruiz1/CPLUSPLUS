#include <iostream>
#include "Point.h"
#include <vector>
#include <string>
#include <tuple>
#include <utility>

using namespace std;

void printOut(vector<Point> points) {
	for (const Point& n : points) {
		cout << n << endl;
	}
}

/*
* Internal method that merges two sorted halves
* of a subarray.
* Points is an array of points.
* tmpArray is an array to place the merged result.
* leftPos is the left-most index of the subarray.
* rightPos is the index of the start of the second half.
* rightEnd is the right-most index of the subarray.
*
*/
void merge(vector<Point>& points, vector<Point>& tmpArray, int leftPos, int rightPos, int rightEnd) {

	int leftEnd = rightPos - 1;
	int tmpPos = leftPos;
	int numElements = rightEnd - leftPos + 1;

	//Main loop
	while (leftPos <= leftEnd && rightPos <= rightEnd) {
		if (points[leftPos].getX() <= points[rightPos].getX()) {
			tmpArray[tmpPos++] = move(points[leftPos++]);
		}
		else {
			tmpArray[tmpPos++] = move(points[rightPos++]);
		}
	}

	while (leftPos <= leftEnd) { //  Copy rest of first half
		tmpArray[tmpPos++] = move(points[leftPos++]);
	}
	while (rightPos <= rightEnd) { //  Copy rest of right half
		tmpArray[tmpPos++] = move(points[rightPos++]);
	}
	//  Copy tmpArray back
	for (int i = 0; i < numElements; ++i, --rightEnd) {
		points[rightEnd] = move(tmpArray[rightEnd]);
	}
}


/*
* Internal method that makes recursive calls.
* points is an array of Points.
* tmpArray is an array to place the merged result.
* left is the left-most- index of the subarray.
* right is the right-most index of the subarray.
*/
void mergeSort(vector<Point>& points, vector<Point>& tmpArray, int left, int right) {
	if (left < right) {
		int center = (left + right) / 2;
		mergeSort(points, tmpArray, left, center);
		mergeSort(points, tmpArray, center + 1, right);
		merge(points, tmpArray, left, center + 1, right);
	}
}


tuple<Point, Point, int> bruteForce(vector<Point>& points) {
	double distance;
	double minDistance = std::numeric_limits<double>::max();
	Point p1;
	Point p2;


	for (size_t i = 0; i < points.size(); i++) {
		for (size_t j = 1; j < points.size(); j++) {
			distance = points[i].distance(points[j]);
			if (distance < minDistance && points[i] != points[j]) {
				minDistance = distance;
				p1 = points[i];
				p2 = points[j];
			}
		}
	}
	return { p1, p2, minDistance };
}

pair<Point, Point> closest(vector<Point> points) {

	if (points.size() <= 4) {
		tuple<Point, Point, int> result = bruteForce(points);
		return make_pair(get<0>(result), get<1>(result));
	}
	/*
	Point mid = points[points.size() / 2];
	vector<Point> left(points.begin(), points.begin() + (points.size()/2));
	vector<Point> right(points.begin() + (points.size()/2), points.end());

	if (left.size() < right.size()) {

	}
	*/

}

int main() {
	vector<Point> points;
	vector<Point> tmpArray;

	string fileName;
	
	double x;
	double y;
	
	ifstream file;

	cout << "Enter Filename: ";
	cin >> fileName;

	file.open(fileName);
	if (file) {
		while (file >> x >> y) {
			points.push_back(Point(x, y));
		}
		tmpArray.resize(points.size());
		file.close();
		//Sort vector
		mergeSort(points, tmpArray, 0, points.size() - 1);

		printOut(points);

	}
	else {
		"Can't open file";
	}
}


