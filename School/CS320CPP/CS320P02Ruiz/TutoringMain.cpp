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
	mergeSort(a, tmpArray, 0, n - 1, compare);
}

// A recursive function to find the
// smallest distance. The array P contains
// all points sorted according to x coordinate

pair<Point, Point> bruteForce(vector<Point> points, size_t n) {
}



pair<Point, Point> closestUtil(vector<Point> points, size_t n)
{
	
}


//The main function that finds the smallest distance
//This method mainly uses closestUtil()

template<typename T>
pair<Point, Point> closest(vector<Point>& points, T compare ) {
	Point p1;
	Point p2;

	compare(p1, p2);


	
	
}

int main() {
	vector<Point> points;


	closest(points, Point::CompareXCoordinate());


}
