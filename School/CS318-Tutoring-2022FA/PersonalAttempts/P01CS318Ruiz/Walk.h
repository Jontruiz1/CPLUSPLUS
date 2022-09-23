#include <iostream>
#include <cmath>

class Walk {
public:
	Walk() {
		totalDist = 0;
		currDist = 0;
		x = 0;
		y = 0;
		angle = 0;
	}

	void updateDistance()  {
		currDist = (rand() + 1) % 100;
		totalDist += currDist;
	}

	void updateAngle() {
		double currangle;
		currangle = (rand() + 1) % 360;
		angle = currangle * (3.1419 * 180);
	}

	void walk() {
		updateDistance();
		updateAngle();
		x = currDist * (cos(angle));
		y = currDist * (sin(angle));
	}
	double getDist() {
		return totalDist;
	}

	double getX() {
		return x;
	}
	double getY() {
		return y;
	}

private:
	double x;
	double y;
	double currDist;
	double totalDist;
	double angle;

};