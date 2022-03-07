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
void merge(vector<Point>& a, vector<Point>& tmpArray, int leftPos, int rightPos, int rightEnd, Comparable compare) {
    int leftEnd = rightPos - 1;
    int tmpPos = leftPos;
    int numElements = rightEnd - leftPos + 1;

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
/**
 * Internal method that makes recursive calls.
 * a is an array of Comparable items.
 * tmpArray is an array to place the merged result.
 * left is the left-most index of the subarray.
 * right is the right-most index of the subarray.
 */
template <typename Comparable>
void mergeSort(vector<Point>& a, vector<Point>& tmpArray, int left, int right, Comparable compare)
{
    if (left < right)
    {
        int center = (left + right) / 2;
        mergeSort(a, tmpArray, left, center, compare);
        mergeSort(a, tmpArray, center + 1, right, compare);
        merge(a, tmpArray, left, center + 1, right, compare);
    }
}


/**
 * Mergesort algorithm (driver).
 */
template <typename Comparable>
void mergeSort(vector<Point>& a, Comparable compare)
{
    vector<Point> tmpArray(a.size());

    mergeSort(a, tmpArray, 0, a.size() - 1, compare);
}


/**
 * Internal method that merges two sorted halves of a subarray.
 * a is an array of Comparable items.
 * tmpArray is an array to place the merged result.
 * leftPos is the left-most index of the subarray.
 * rightPos is the index of the start of the second half.
 * rightEnd is the right-most index of the subarray.
 */
pair<Point, Point> bruteForce(vector<Point>points, size_t n)
{
    double min = numeric_limits<double>::max();
    Point p1;
    Point p2;


    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (points[i].distance(points[j]) < min) {
                min = points[i].distance(points[j]);
                p1 = points[i];
                p2 = points[j];
            }
        }
    }
    return { p1, p2 };
}

// A utility function to find
// minimum of two float values
pair<Point, Point> min(pair<Point, Point> x, pair<Point, Point> y)
{
    double xdist = get<0>(x).distance(get<1>(x));
    double ydist = get<0>(y).distance(get<1>(y));
    pair<Point, Point> result = xdist < ydist ? x : y;

    return result;
}


// A utility function to find the
// distance between the closest points of
// strip of given size. All points in
// strip[] are sorted according to
// y coordinate. They all have an upper
// bound on minimum distance as d.
// Note that this method seems to be
// a O(n^2) method, but it's a O(n)
// method as the inner loop runs at most 6 times
pair<Point, Point> stripClosest(vector<Point>& strip, int size, double d)
{
    double min = d; // Initialize the minimum distance as d
    Point p1;
    Point p2;

    mergeSort(strip, Point::CompareYCoordinate());

    // Pick all points one by one and try the next points till the difference
    // between y coordinates is smaller than d.
    // This is a proven fact that this loop runs at most 6 times
    for (int i = 0; i < size; ++i) {
        for (int j = i + 1; j < size && (strip[j].getY() - strip[i].getY()) < min; ++j) {
            if (strip[j].distance(strip[i]) < min) {
                min = strip[j].distance(strip[i]);
                p1 = strip[i];
                p2 = strip[j];
            }
        }
    }
    return { p1, p2 };
}

// A recursive function to find the
// smallest distance. The array P contains
// all points sorted according to x coordinate
pair<Point, Point> closestUtil(vector<Point> points, size_t n)
{

    // If there are 2 or 3 points, then use brute force
    if (n <= 4) {
        return bruteForce(points, n);
    }

    // Find the middle point
    int mid = n / 2;
    Point midPoint = points[mid];

    // Consider the vertical line passing
    // through the middle point calculate
    // the smallest distance dl on left

    pair<Point, Point> dl = closestUtil(vector<Point>(points.begin(), points.begin()+mid), mid);
    pair<Point, Point> dr = closestUtil(vector<Point>(points.begin()+mid, points.end()), n - mid);

    double dldist = get<0>(dl).distance(get<1>(dl));
    double drdist = get<0>(dr).distance(get<1>(dr));




    // Build an array strip[] that contains
    // points close (closer than d)
    // to the line passing through the middle point
    vector<Point> strip(n);
    int j = 0;
    for (int i = 0; i < n; i++) {
        if (abs(points[i].getX() - midPoint.getX()) < get<0>(d).distance(get<1>(d))) {
            strip[j] = points[i], j++;
        }
    }

    // Find the closest points in strip.
    // Return the minimum of d and closest
    // distance is strip[]
    pair<Point, Point> stripped = stripClosest(strip, j, get<0>(d).distance(get<1>(d)));


}

// The main function that finds the smallest distance
// This method mainly uses closestUtil()
pair<Point, Point> closest(vector<Point>& points){
    mergeSort(points, Point::CompareXCoordinate());

    // Use recursive function closestUtil()
    // to find the smallest distance
    return closestUtil(points, points.size());
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
    pair<Point, Point> result = closest(points);
    cout << get<0>(result);

}
