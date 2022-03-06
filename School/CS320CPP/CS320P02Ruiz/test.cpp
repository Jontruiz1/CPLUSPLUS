// Evan Huber
// CS320 Project 2
// Use both a brute force and a divide and conquer algorithm

#include "Point.h"
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <iterator>
#include <fstream>
#include <string>

using namespace std;

template <typename Comparable>
void mergeSort(vector<Comparable>& a,
	vector<Comparable>& tmpArray, int left, int right, Comparable cmp);

template <typename Comparable>
void mergeSort(vector<Point>& a, Comparable cmp);

template <typename Comparable>
void merge(vector<Comparable>& a, vector<Comparable>& tmpArray,
	int leftPos, int rightPos, int rightEnd, Comparable cmp);

pair<Point, Point> bruteForce(vector<Point> pVec);
pair<Point, Point> closest(vector<Point>& points);


int main()
{
	vector<Point> points;
	string choice;
	cout << "Available files:\n\n 1. file7.txt - n size of 7\n 2. file50000.txt - n size of 50,000\n\nEnter Filename: ";
	cin >> choice;
	ifstream inFile(choice);

	if (inFile.is_open())
	{
		string x, y;
		while (inFile.good())
		{
			inFile >> x;
			inFile >> y;
			Point p = Point(stod(x), stod(y));
			points.push_back(p);
		}
	}
	mergeSort(points, Point::CompareXCoordinate());
	pair<Point, Point> closePoints = closest(points);


	double dist = (closePoints.first).distance(closePoints.second);

	cout << "closest points are (" << closePoints.first.getX() << ", " <<
		closePoints.first.getY() << ") and (" << closePoints.second.getX() << ", "
		<< closePoints.second.getY() << ")\n\nThe distance between the two is " << dist << endl;

	inFile.close();
	return 0;
}




pair<Point, Point> bruteForce(vector<Point> pVec)
{
	/* Read all points (n points) into an array
	*  for each input point pi = (xi, yi)
	*		for each other point pj = (xj, yj)
	*			compute distance between pi and pj
	*			if ( distance < minimum distance ) minimum distance = distance
	*/
	double lowest = DBL_MAX;
	pair<Point, Point> closest;
	for (int i = 0; i < pVec.size(); i++)
	{
		for (int j = i + 1; j < pVec.size(); j++)
		{
			double current = pVec[i].distance(pVec[j]);
			if (current < lowest)
			{
				lowest = current;
				closest.first = pVec[i];
				closest.second = pVec[j];

			}
			
		}
	}
	return closest;

}

pair<Point, Point> stripClosest(vector<Point>& points, int size, float d)
{
	float min = d; // Initialize the minimum distance as d
	Point p1;
	Point p2;

	mergeSort(points, Point::CompareYCoordinate());

	// Pick all points one by one and try the next points till the difference
	// between y coordinates is smaller than d.
	// This is a proven fact that this loop runs at most 6 times
	for (int i = 0; i < size; ++i) {
		for (int j = i + 1; j < size && (points[j].getY() - points[i].getY()) < min; ++j) {
			if (points[i].distance(points[j]) < min)
			{
				min = points[i].distance(points[j]);
				p1 = points[i];
				p2 = points[j];

			}
		}
	}
	return make_pair(p1, p2);
}
pair<Point, Point> closest(vector<Point>& points)
{
	
	int n = points.size();
	if (n <= 4)
		return bruteForce(points);

	// Find the middle point
	int mid = n / 2;
	Point midPoint = points[mid];


	vector<Point> fHalf(points.begin(), points.begin() + mid);
	vector<Point> sHalf(points.begin() + mid, points.end());
	// Consider the vertical line passing
	// through the middle point calculate
	// the smallest distance dl on left
	// of middle point and dr on right side
	pair<Point, Point> dl = closest(fHalf);
	pair<Point, Point> dr = closest(sHalf);

	// Find the smaller of two distances
	float d = (dl.first.distance(dl.second) < dr.first.distance(dr.second)) ? dl.first.distance(dl.second) : dr.first.distance(dr.second);


	// Build a vector strip that contains
	// points close (closer than d)
	// to the line passing through the middle point
	vector<Point> strip(n);
	int j = 0;
	for (int i = 0; i < n; i++) {
		if (abs(points[i].getX() - midPoint.getX()) < d) {
			strip[j] = points[i];
			j++;
			//cout << strip[j] << " is now in the array\n";
		}
	}
	return stripClosest(strip, j, d);
}

template <typename Comparable>
void mergeSort(vector<Point>& a, Comparable cmp)
{

	vector<Point> tmpArray(a.size());

	mergeSort(a, tmpArray, 0, a.size() - 1, cmp);
}


template <typename Comparable>
void mergeSort(vector<Point>& a,
	vector<Point>& tmpArray, int left, int right, Comparable cmp)
{

	if (left < right)
	{
		int center = (left + right) / 2;
		mergeSort(a, tmpArray, left, center, cmp);
		mergeSort(a, tmpArray, center + 1, right, cmp);
		merge(a, tmpArray, left, center + 1, right, cmp);
	}
}

/**
 * Internal method that merges two sorted halves of a subarray.
 * a is an array of Comparable items.
 * tmpArray is an array to place the merged result.
 * leftPos is the left-most index of the subarray.
 * rightPos is the index of the start of the second half.
 * rightEnd is the right-most index of the subarray.
 */
template <typename Comparable>
void merge(vector<Point>& a, vector<Point>& tmpArray,
	int leftPos, int rightPos, int rightEnd, Comparable cmp)
{
	int leftEnd = rightPos - 1;
	int tmpPos = leftPos;
	int numElements = rightEnd - leftPos + 1;

	// Main loop
	while (leftPos <= leftEnd && rightPos <= rightEnd)
		if (cmp(a[leftPos], a[rightPos]))
			tmpArray[tmpPos++] = std::move(a[leftPos++]);
		else
			tmpArray[tmpPos++] = std::move(a[rightPos++]);

	while (leftPos <= leftEnd)    // Copy rest of first half
		tmpArray[tmpPos++] = std::move(a[leftPos++]);

	while (rightPos <= rightEnd)  // Copy rest of right half
		tmpArray[tmpPos++] = std::move(a[rightPos++]);

	// Copy tmpArray back
	for (int i = 0; i < numElements; ++i, --rightEnd)
		a[rightEnd] = std::move(tmpArray[rightEnd]);
}