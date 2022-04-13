#include <iostream>
#include <fstream>
#include "Tour.h"

ostream& operator<<(ostream& out, City rhs) {
	out << rhs.getCityName() << " " << rhs.getX() << " " << rhs.getY();
	return out;
}

double acceptanceProbability(double currDis, double newDis, double temp) {
	if (newDis < currDis) {
		return 1.0;
	}
	return exp((currDis - newDis) / temp);
}

int main() {
	// seed
	srand(unsigned (time(NULL)));																								
	ifstream file;
	string fileName;
	Tour* currentSolution = new Tour();
	Tour* newSolution = nullptr;
	Tour* best = nullptr;
	vector<City> cities;

	double coolingRate, randDouble, startingTemp;
	int statesTested = 0, statesAccepted = 0;
	int rand1 = 0, rand2 = 0;
	

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
		while (startingTemp > 1) {
			size_t currentSize = currentSolution->tourSize();
			rand1 = rand() % currentSize;
			rand2 = rand() % currentSize;																			// generate random indecies
			while (rand1 == rand2) { rand2 = rand() % currentSize; }

			newSolution = new Tour(currentSolution->getTour());														// create new solution from current 

			City swap1 = newSolution->getCity(rand1);
			City swap2 = newSolution->getCity(rand2);

			newSolution->setCity(rand2, swap1);												
			newSolution->setCity(rand1, swap2);																		// swap randomly chosen cities

			double currDis = currentSolution->getTotalDistance();
			double newDis = newSolution->getTotalDistance();														// calculate currentSolution distance and new solution distance

			
			randDouble = ((double)rand()) / RAND_MAX;																// generate rand double between 0 and 1
			if (acceptanceProbability(currDis, newDis, startingTemp) > randDouble) {								// compute acceptance probabiity for current solution and decide if newSolution is accepted
				currentSolution = new Tour(newSolution->getTour());
				++statesAccepted;
			}

			if (currentSolution->getTotalDistance() < best->getTotalDistance()) {									// update best solution
				best = currentSolution;
			}

			++statesTested;																							// cooling and states tested
			startingTemp *= (1 - coolingRate);
		}

		cout << "\nNumber of new states tested: " << statesTested << endl;
		cout << "Number of new states accepted: " << statesAccepted << endl << endl;

		cout << "Final Solution Distance: " << best->getTotalDistance();
		best->printTour();
	}
}