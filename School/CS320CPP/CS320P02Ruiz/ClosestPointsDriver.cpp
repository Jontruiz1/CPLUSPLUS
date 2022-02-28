#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <utility>
#include <algorithm>
#include <iomanip>
#include "Point.h"

using namespace std;

void printOut(vector<Point> points) {
	for (const Point& n : points) {
		cout << n << endl;
	}
}

template<typename T>
void merge(vector<Point>& points, vector<Point>& tmpArray, int leftPos, int rightPos, int rightEnd, T compare) {

	int leftEnd = rightPos - 1;
	int tmpPos = leftPos;
	int numElements = rightEnd - leftPos + 1;

	//Main loop
	while (leftPos <= leftEnd && rightPos <= rightEnd) {
		if (compare(points[leftPos], points[rightPos])) {
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
template<typename T>
void mergeSort(vector<Point>& points, vector<Point>& tmpArray, int left, int right, T compare ) {
	if (left < right) {
		int center = (left + right) / 2;
		mergeSort(points, tmpArray, left, center, compare);
		mergeSort(points, tmpArray, center + 1, right, compare);
		merge(points, tmpArray, left, center + 1, right, compare);
	}
}

tuple<Point, Point, double> bruteForce(vector<Point>& points) {
	Point p1;
	Point p2;
	double minDistance = std::numeric_limits<double>::max();

	for (int i = 0; i < points.size(); ++i) {
		for (int j = i+1; j < points.size(); ++j) {
			if (points[i].distance(points[j]) < minDistance) {
				minDistance = points[i].distance(points[j]);
				p1 = points[i];
				p2 = points[j];
			}
		}
	}
	return {p1, p2, minDistance};
}

tuple<Point, Point, double> closestAcrossStrip(vector<Point> strip, unsigned size, const double d) {
	double min = d;
	vector<Point> tmpArray(strip.size());
	Point p1;
	Point p2;
	
	mergeSort(strip, tmpArray, 0, size-1, Point::CompareYCoordinate());

	for (unsigned i = 0; i < size; ++i) {
		for (unsigned j = i + 1; j < size && (abs(strip[j].getY() - strip[i].getY())) < min; ++j) {
			if (strip[j].distance(strip[i]) < min) {
				min = strip[j].distance(strip[i]);
				p1 = strip[i];
				p2 = strip[j];
			}
		}
	}

	return {p1, p2, min};

}


tuple<Point, Point, double> closestUtil(vector<Point> points, size_t n) {

	if (points.size() <= 4) {
		return bruteForce(points);
	}

	size_t mid = n / 2;
	Point midPoint = points[mid];

	tuple<Point, Point, double> dl = (closestUtil(vector<Point>(points.begin(), points.begin() + mid), mid));
	tuple<Point, Point, double> dr = (closestUtil(vector<Point>(points.begin() + mid, points.end()), n - mid));
	
	//if min of get<2>(dl) is < get<2>(dr) then you get the point values of dl
	//else get the values of dr, 
	//I just thought it looked more compact than the if else
	Point p1 = get<2>(dl) < get<2>(dr) ? get<0>(dl) : get<0>(dr);
	Point p2 = get<2>(dl) < get<2>(dr) ? get<1>(dl) : get<1>(dr);
	double d = min(get<2>(dl), get<2>(dr));
	/*I just thought doing it this way was funny, works the same way as the code above
	Point p1 = get<true << true>(dl) < get<true << true>(dr) ? get<false>(dl) : get<false>(dr);
	Point p2 = get<true << true>(dl) < get<true << true>(dr) ? get<true>(dl) : get<true>(dr);*/
	
	//builds the strip vector for step 4
	vector<Point> strip(n);
	int j = 0;
	for (int i = 0; i < n; i++) {
		if (abs(points[i].getX() - midPoint.getX()) < d) {
			strip[j] = points[i], j++;
		}
	}

	//  sorts strip and sets up the points for the minimum distance in the strip
	tuple<Point, Point, double> result = closestAcrossStrip(strip, j, d);
	double stripMin = get<2>(result);

	//Basically doing min(d, stripMin) but I need to assign p1 and p2 to the other Point values if they have a shorter distance so I do this if check
	if (stripMin < d) {
		p1 = get<0>(result);
		p2 = get<1>(result);
		d = stripMin;
	}
	
	return { p1, p2, d };
}

pair<Point, Point>closest(vector<Point>& points) {
	vector<Point> tmpArray(points.size());
	mergeSort(points, tmpArray, 0, points.size() - 1, Point::CompareXCoordinate());
	tuple<Point, Point, double> result = closestUtil(points, points.size());

	return {get<0>(result), get<1>(result)};

}

int readIn(ifstream& file) {
	pair<Point, Point> result;
	vector<Point> points;
	Point p1, p2;
	streamsize ss = cout.precision();
	double minDistance;

	if (file.fail()) {
		cout << "File failed to open";
	}
	else {
		while (file >> ws && !file.eof()) {
			Point p;
			file >> p;
			points.push_back(p);
		}
		if (points.size() <= 1) {
			cout << "Not enough points";
			return 0;
		}
		file.close();

		result = closest(points);
		p1 = get<0>(result);
		p2 = get<1>(result);
		minDistance = p1.distance(p2);

		cout << fixed << setprecision(2);
		cout << "Closest points are: (" << p1.getX() << ", " << p1.getY() << ") and (" << p2.getX() << ", " << p2.getY() << ") with distance = " << setprecision(ss) << minDistance;
	}
}

/*
int main() {
	string fileName;
	ifstream file;
	
	cout << "Enter Filename: ";
	cin >> fileName;

	file.open(fileName);
	readIn(file);
	
}
*/

