#include "Tour.h"
#include <iostream>
#include <algorithm>
#include <random>

Tour::Tour() {
	tour = {City("Null", 0, 0)};
	distance = 0;
}

Tour::Tour(const vector<City>& oldTour) {
	tour = oldTour;
}


// I'm not sure what this function and setCity are supposed to do in relation to the Tour
City& Tour::getCity(int index) {
	return tour[index];
}

void Tour::setCity(int index, City& city) {
	tour[index] = city;
	distance = 0;
}

// return tour vector
vector<City>& Tour::getTour() {
	return tour;
}
// return the size of the tour
size_t Tour::tourSize() {
	return tour.size();
}

// prints out tour
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
	int i;

	if (distance == 0) {
		for (i = 0; i < tour.size()-1; ++i) {
			distance += euclideanDistance(tour[i], tour[i + 1]);
		}
		distance += euclideanDistance(tour[i], tour[0]);
	}

	return distance;
}

void Tour::generateInitialTour(vector<City>& destinationCities) {
	tour = destinationCities;
	shuffle(tour.begin(), tour.end(), default_random_engine(time(NULL)));
}