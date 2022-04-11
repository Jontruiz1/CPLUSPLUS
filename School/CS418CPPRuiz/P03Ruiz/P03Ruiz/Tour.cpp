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
	int i;

	for (i = 0; i < tour.size() - 1; ++i) {
		distance += euclideanDistance(tour[i], tour[i + 1]);
	}

	distance += euclideanDistance(tour[i], tour[0]);
}

City& Tour::getCity() {
	City temp("null", 0, 0);
	return temp;
}

void Tour::setCity(City& city) {

}


vector<City>& Tour::getTour() {
	return tour;
}

size_t Tour::tourSize() {
	return tour.size();
}

void Tour::printTour() {
	cout << "\nTour:" << endl;
	for (int i = 0; i < tour.size(); ++i) {
		cout << tour[i].getCityName();
		cout << (i == tour.size() - 1 ? " " : " -> ");
	}
	cout << endl;
}

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