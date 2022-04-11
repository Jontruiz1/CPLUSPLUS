#ifndef __CITY__
#define __CITY__

#include <string>
using namespace std;

class City {

public:
	City() : cityName("Null"), x(0), y(0) {};
	City(string c, int xc, int yc) : cityName(c), x(xc), y(yc) {};
	string getCityName() { return cityName; }
	int getX() { return x; }
	int getY() { return y; }


	
private:
	
	string cityName;
	int x;
	int y;
};

ostream& operator<<(ostream& out, City rhs) {
	out << rhs.getCityName() << " " << rhs.getX() << " " << rhs.getY();
	return out;
}
#endif