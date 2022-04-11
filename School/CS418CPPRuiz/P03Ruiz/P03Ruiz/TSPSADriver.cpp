#include <iostream>
#include <fstream>
#include "Tour.h"

ostream& operator<<(ostream& out, City rhs) {
	out << rhs.getCityName() << " " << rhs.getX() << " " << rhs.getY();
	return out;
}

int main() {
	// seed
	srand(time(NULL));

	// needed
	ifstream file;
	string fileName;
	Tour* currentSolution = new Tour();
	Tour* best = nullptr;
	vector<City> cities;

	double coolingRate, acceptanceProbability, randDouble;
	int startingTemp, statesTested = 0, statesAccepted = 0;
	int rand1 = 0, rand2 = 0;

	// unsure if needed
	Tour* prevSolution = nullptr;

	cout << "*** TSP using Simulated Annealing ***";
	cout << "\n\nStarting Temperature: ";
	cin >> startingTemp;

	cout << "\n\nCooling Rate: ";
	cin >> coolingRate;

	cout << "\n\nPlease enter a file name (quit to end): ";
	cin >> fileName;
	if (fileName == "quit") return 0;


	file.open(fileName);

	if (file.fail()) {
		cout << "\n\nCould not find specified file.";
	}
	else {
		// file readin
		while (!file.eof()) {
			string name;
			getline(file, name);
			
			int x, y;
			file >> x >> y >> ws;
			City temp(name, x, y);
			cities.push_back(temp);
		}
		// cities printout
		cout << "\n\nCities: \n";
		for (const City& city : cities) { cout << "\t" << city << endl; }
		cout << endl;
		
		// generate initial tour and print it out
		currentSolution->generateInitialTour(cities);
		cout << "Initial Solution Distance : " << currentSolution->getTotalDistance();
		currentSolution->printTour();

		best = new Tour(currentSolution->getTour());
		// cooling
		while (startingTemp >= 1) {
			size_t currentSize = currentSolution->tourSize();

			// prev solution saved
			prevSolution = currentSolution;
			// create new solution from current solution
			// the new solution here will just be named currentSolution
			currentSolution = new Tour(currentSolution->getTour());


			// randomly choose two cities from currentSolution and swap their locations
			// calculate currentSolution distance and new solution distance
			currentSolution->getTotalDistance();

			

			// computer acceptance probabiity for current solution

			// generate rand double between 0 and 1
			randDouble = ((double)rand()) / RAND_MAX;
			statesTested++;
			startingTemp -= coolingRate;
		}

		cout << "Number of new states tested: " << statesTested << endl;
		cout << "Number of new states accepted: " << statesAccepted << endl << endl;

		cout << "Final Solution Distance: " << best->getTotalDistance() << endl;
		best->printTour();
	}
}