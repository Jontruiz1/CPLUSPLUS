#include <iostream>
#include <fstream>
#include "Tour.h"



int main() {
	int startingTemp;
	double coolingRate;
	string fileName;
	ifstream file;
	vector<City> cities;

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
		while (!file.eof()) {
			string name;
			getline(file, name);
			
			int x, y;
			file >> x >> y >> ws;
			City temp(name, x, y);
			cities.push_back(temp);
		}
		cout << "\n\nCities: \n";
		for (const City& city : cities) { cout << "\t" << city; }
	}


}