#include "Tour.h"
#include <iostream>
#include <algorithm>
#include <random>

Tour::Tour() {
	tour = {City("Null", 0, 0)};
	distance = 0;
}

Tour::Tour(const Tour& oldTour) {
	int i;

	tour = oldTour.tour;
	distance = oldTour.distance;
	

	for (i = 0; i < tour.size() - 1; ++i) {
		distance += euclideanDistance(tour[i], tour[i + 1]);
	}

	distance += euclideanDistance(tour[i], tour[0]);
}


// I'm not sure what this function and setCity are supposed to do in relation to the Tour
City& Tour::getCity() {
	City temp("null", 0, 0);
	return temp;
}

void Tour::setCity(City& city) {
	

}

// just return the tour I guess?
Tour& Tour::getTour() {
	return *this;
}
// return the size of the tour? This one is probably fine
size_t Tour::tourSize() {
	return tour.size();
}

// Just print out the tour as shown in the spec, this one is also probably fine
void Tour::printTour() {
	cout << "\nTour:" << endl;
	for (int i = 0; i < tour.size(); ++i) {
		cout << tour[i].getCityName();
		cout << (i == tour.size() - 1 ? " " : " -> ");
	}
	cout << endl;
}


// Should this just return distance or also calculate the distance?
double Tour::getTotalDistance() {
	
	return distance;
}

void Tour::generateInitialTour(vector<City>& destinationCities) {
	tour = destinationCities;
	int i;
	shuffle(tour.begin(), tour.end(), default_random_engine(time(NULL)));


	for (i = 0; i < tour.size() - 1; ++i) {
		distance += euclideanDistance(tour[i], tour[i + 1]);
	}
	distance += euclideanDistance(tour[i], tour[0]);
}