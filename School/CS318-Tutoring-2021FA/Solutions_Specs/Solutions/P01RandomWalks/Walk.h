//P01: Walk.h
#pragma once
#include <iostream>
#include <iomanip>
#include <math.h>
#include "UtilRand.h"
using namespace std;

class Walk {
public:
	Walk() : x(0.0), y(0.0), distance(0.0) {}

	double getX() const { return x; }
	double getY() const { return y; }
	double getDistance() const { return distance; }

	void setX(double x) { this->x = x; }
	void setY(double y) { this->y = y; }
	void setDistance(double distance) { this->distance = distance; }

	int generateAngle() {
		return generateRandomInRange(1, 359);
	}

	int generateLength() {
		return generateRandomInRange(1, 100);
	}

	double convertToRadians(double degree) {
		double pi = 3.14159265359;
		return (degree * (pi / 180));
	}

	void walkAgain() {
		int angle = generateAngle();
		int length = generateLength();
		//cout << "Degree: " << angle << " Length: " << length;
		double radians = convertToRadians(angle);
		x = x + length * cos(radians);
		y = y + length * sin(radians);
		distance = distance + length;
	}

private:
	double x;
	double y;
	double distance;
};

ostream& operator<<(ostream& os, const Walk& w)
{
	os << "  Point: " << fixed << setprecision(2) << w.getX() << ", " << w.getY()
		<< "   Distance: " << w.getDistance() << endl;
	return os;
}

