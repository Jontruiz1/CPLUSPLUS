#ifndef __CITY__
#define __CITY__

#include <string>
#include <iostream>
using namespace std;

class City {

public:
	City() : cityName("Null"), x(0), y(0) {};
	City(string newcity, int newx, int newy) : cityName(newcity), x(newx), y(newy) {};
	string getCityName() { return cityName; }
	int getX() { return x; }
	int getY() { return y; }
	void setX(int newx) { x = newx; }
	void setY(int newy) { y = newy; }
	void setName(string name) { cityName = name; }
private:
	string cityName;
	int x;
	int y;
};


#endif