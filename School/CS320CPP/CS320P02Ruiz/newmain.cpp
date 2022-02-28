#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <utility>
#include "Point.h"


using namespace std;
/**
 * Internal method that merges two sorted halves of a subarray.
 * a is an array of Comparable items.
 * tmpArray is an array to place the merged result.
 * leftPos is the left-most index of the subarray.
 * rightPos is the index of the start of the second half.
 * rightEnd is the right-most index of the subarray.
 */
template <typename Comparable>
void merge(vector<Point>& a, vector<Point>& tmpArray, size_t leftPos, size_t rightPos, size_t rightEnd, Comparable compare)
{
	size_t leftEnd = rightPos - 1;
	size_t tmpPos = leftPos;
	size_t numElements = rightEnd - leftPos + 1;

	// Main loop
	while (leftPos <= leftEnd && rightPos <= rightEnd) {
		if (compare(a[leftPos], a[rightPos])) {
			tmpArray[tmpPos++] = move(a[leftPos++]);
		}
		else {
			tmpArray[tmpPos++] = move(a[rightPos++]);
		}
	}

	while (leftPos <= leftEnd) {    // Copy rest of first half
		tmpArray[tmpPos++] = move(a[leftPos++]);
	}

	while (rightPos <= rightEnd) {  // Copy rest of right half
		tmpArray[tmpPos++] = move(a[rightPos++]);
	}

	// Copy tmpArray back
	for (int i = 0; i < numElements; ++i, --rightEnd) {
		a[rightEnd] = move(tmpArray[rightEnd]);
	}

} 
template <typename Comparable>
void mergeSort(vector<Point>& a, vector<Point>& tmpArray, size_t left, size_t right, Comparable compare)
{
	if (left < right)
	{
		size_t center = (left + right) / 2;
		mergeSort(a, tmpArray, left, center, compare);
		mergeSort(a, tmpArray, center + 1, right, compare);
		merge(a, tmpArray, left, center + 1, right, compare);
	}
}

///**
// * Mergesort algorithm (driver).
// */
template <typename Comparable>
void mergeSort(vector<Point>& a, size_t n, Comparable compare)
{
	vector<Point> tmpArray(n);
	mergeSort(a, tmpArray, 0, n-1, compare);
}

// A recursive function to find the
// smallest distance. The array P contains
// all points sorted according to x coordinate
 
pair<Point, Point> bruteForce(vector<Point> points, size_t n) {
	double min = numeric_limits<double>::min();
	double curr_d;
	Point p1;
	Point p2;

	cout << "this ran";

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			curr_d = points[i].distance(points[j]);
			if (curr_d < min) {
				p1 = points[i];
				p2 = points[j];
				min = curr_d;
			}
		}
	}

	return { p1, p2 };

}



pair<Point, Point> closestUtil(vector<Point> points, size_t n)
{
	// If there are 2 or 3 points, then use brute force
	if (n <= 4){
		return bruteForce(points, n);
	}

	// Find the middle point
	size_t mid = n / 2;
	Point midPoint = points[mid];

	// Consider the vertical line passing
	// through the middle point calculate
	// the smallest distance dl on left
	// of middle point and dr on right side

	//float dl = closestUtil(points, mid);
	//float dr = closestUtil(P + mid, n - mid);

	// Find the smaller of two distances
	//float d = min(dl, dr);

	//// Build an array strip[] that contains
	//// points close (closer than d)
	//// to the line passing through the middle point
	//Point strip[n];
	//int j = 0;
	//for (int i = 0; i < n; i++)
	//	if (abs(P[i].x - midPoint.x) < d)
	//		strip[j] = P[i], j++;

	//// Find the closest points in strip.
	//// Return the minimum of d and closest
	//// distance is strip[]
	//return min(d, stripClosest(strip, j, d));
	return { 0, 1 };
}


 //The main function that finds the smallest distance
 //This method mainly uses closestUtil()

pair<Point, Point> closest(vector<Point>& points) {
	size_t n = points.size();
	mergeSort(points, n, Point::CompareXCoordinate());

	// Use recursive function closestUtil()
	// to find the smallest distance

	//return { 0, 1 };

	return closestUtil(points, n);
}

int main() {
	string fileName;
	ifstream file;
	vector<Point> points;
	
	// if you want, check file.fail()
	// if that's true, file failed to open, print out error message

	cout << "Enter filename: ";
	cin >> fileName;

	file.open(fileName);


	if (file.fail()) {
		cout << "File could not be found";
	}
	else {
		while (!file.eof()) {
			Point a;

			file >> a;
			points.push_back(a);
		}
	}
	file.close();
	closest(points);
	for (auto i : points) {
		cout << i << endl;
	}



}
