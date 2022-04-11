#include <iostream>
#include <fstream>
#include "Tour.h"

ostream& operator<<(ostream& out, City rhs) {
	out << rhs.getCityName() << " " << rhs.getX() << " " << rhs.getY();
	return out;
}

int main() {
	// needed
	ifstream file;
	string fileName;
	Tour* currentSolution = nullptr;
	Tour* best = nullptr;
	vector<City> cities;

	double coolingRate, acceptanceProbability;
	int startingTemp, statesTested = 0, statesAccepted = 0;
	
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
			prevSolution = currentSolution;
			currentSolution = new Tour(currentSolution->getTour());
			delete prevSolution;

			statesTested++;
			startingTemp -= coolingRate;
		}
		delete currentSolution;
		cout << "Number of new states tested: " << statesTested << endl;
		cout << "Number of new states accepted: " << statesAccepted << endl << endl;

		cout << "Final Solution Distance: " << best->getTotalDistance() << endl;
		best->printTour();
	}
}