#ifndef __TOURH__
#define __TOURH__
#include <vector>
#include "City.h"

class Tour {
public:
	Tour();
	Tour(const vector<City>& tour);

	Tour& getTour();
	City& getCity();
	void setCity(City& city);
	size_t tourSize();
	void printTour();
	double getTotalDistance();

	void generateInitialTour(vector<City>& destinationCities);
private:
	static double euclideanDistance(City a, City b) { return sqrt(pow(b.getX() - a.getX(), 2) + pow(a.getY() - a.getY(), 2)); }
	vector<City> tour;
	double distance;
};
#endif