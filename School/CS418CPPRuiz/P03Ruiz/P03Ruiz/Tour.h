#include <vector>
#include "City.h"

class Tour {
public:
	Tour();
	Tour(Tour& rhs);

	Tour& getTour();
	City& getCity();
	size_t tourSize();
	void printTour();
	double getTotalDistance();

	void generateInitialTour(vector<City>& destinationCities);
private:
	static void euclideanDistance(City a, City b);
	vector<City> tour;
	int distance;
};