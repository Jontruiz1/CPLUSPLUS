#pragma once
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Problem {
public:
	// Generates the input track and all holding tracks 
	void generate(int userCarCount, int userholdingCount) {
		// Error validation; sets a minimum of 1 car and 1 holding track
		if (userCarCount < 1) {
			cout << "Invalid amount of cars given. Using minimum car amount of 1." << endl;
			userCarCount = 1;
		}
		if (userholdingCount < 1) {
			cout << "Invalid amount of holding tracks given. Using minimum holding track amount of 1." << endl;
			userholdingCount = 1;
		}

		// Gathers all the inputs for the sequence of cars
		cout << "Enter car sequence on input track: ";
		for (int i = 0; i < userCarCount; ++i) {
			int userCar;
			cin >> userCar;
			inputVect.push_back(userCar);
		}

		// Creates a vector (collection of all holding tracks) in which each element is its own vector (individual holding track)
		for (int i = 0; i < userholdingCount; ++i) {
			vector<int> holdingVect;
			holdingVects.push_back(holdingVect);
		}

		// Saved as a reference for the full amount of cars in the problem
		numCars = userCarCount;
	}
	// Vector that holds all instructions
	vector<string> resultsVect;
	// Used to see if the problem has a solution
	bool isSolvable = true;

	// Attempts to solve the problem using the given values
	void solve() {
		// Keeps going until the output vector has every car in it
		while (outputVect.size() != numCars) {
			// For testing purposes
			cout << "The next car on the input track is " << (!inputVect.empty() ? inputVect.front() : 0) << "." << endl;

			// If the leading car's number is smaller than that of any remaining car, it gets moved to the output track
			if (!inputVect.empty() && smallestLeft(inputVect.front())) {
				outputVect.push_back(inputVect.front());
				resultsVect.push_back("\nMove car " + to_string(inputVect.front()) + " from input track to output track.");
				// For testing purposes
				cout << "\nMove car " << inputVect.front() << " from input track to output track.";
				inputVect.erase(inputVect.begin());
			}
			else {
				// Moves the leading car to the lowest holding track with a number bigger than its
				if (smallestHeld(inputVect.front(), holdingVects)) {
					// Case 1: If the leading car is smaller than the last car on any holding track
					resultsVect.push_back("\nMove car " + to_string(inputVect.front()) + " from input track to holding track 1.");
					// For testing purposes
					cout << "\nMove car " << inputVect.front() << " from input track to holding track 1.";
					holdingVects.front().push_back(inputVect.front());
					inputVect.erase(inputVect.begin());
				}
				else {
					// Case 2: If the leading car is smaller than the last car on a specific holding track
					for (int i = 0; i < holdingVects.size(); ++i) {
						cout << "This is i: " << i << endl;
						if (!inputVect.empty() && holdingVects.at(i).empty()) {
							resultsVect.push_back("\nMove car " + to_string(inputVect.front()) + " from input track to holding track " + to_string(i + 1) + ".");
							// For testing purposes
							cout << "\nMove car " << inputVect.front() << " from input track to holding track " << (i + 1) << ".";
							holdingVects.at(i).push_back(inputVect.front());
							inputVect.erase(inputVect.begin());
							break;
						}
						else if (!inputVect.empty() && smallestLeft(holdingVects.at(i).back())) {
							resultsVect.push_back("\nMove car " + to_string(holdingVects.at(i).back()) + " from holding track " + to_string(i + 1) + " to output track.");
							// For testing purposes
							cout << "\nMove car " << holdingVects.at(i).back() << " from holding track " << (i + 1) << " to output track.";
							outputVect.push_back(holdingVects.at(i).back());
							holdingVects.at(i).erase(holdingVects.at(i).begin());
							break;
						}
						else if (!inputVect.empty() && inputVect.front() < holdingVects.at(i).back()) {
							resultsVect.push_back("\nMove car " + to_string(inputVect.front()) + " from input track to holding track " + to_string(i + 1) + ".");
							// For testing purposes
							cout << "\nMove car " << inputVect.front() << " from input track to holding track " << (i + 1) << ".";
							holdingVects.at(i).push_back(inputVect.front());
							inputVect.erase(inputVect.begin());
							break;
						}
					}
					// For testing purposes
					cout << "'else' for loop broken" << endl;
				}
				//isSolvable = false;
				//return;
			}





			// For testing purposes
			testVects();
		}
		// For testing purposes
		cout << "'while' loop broken" << endl;
	}

	// Prints the contents of every vector (for testing purposes)
	// TODO: Remove when finished
	void testVects() {
		cout << "\nInput track contents: ";
		for (int i = 0; i < inputVect.size(); ++i) {
			cout << inputVect.at(i) << " ";
		}
		cout << "\nOutput track contents: ";
		for (int i = 0; i < outputVect.size(); ++i) {
			cout << outputVect.at(i) << " ";
		}
		cout << "\nNumber of holding tracks: " << holdingVects.size();
		if (!holdingVects.empty()) {
			cout << "\nHolding track(s) contents: ";
			for (int i = 0; i < holdingVects.size(); ++i) {
				cout << "\nHolding track " << i + 1 << ": ";
				for (int j = 0; j < holdingVects.at(i).size(); ++j) {
					cout << holdingVects.at(i).at(j) << " ";
				}
			}
		}
		cout << endl;
	}
private:
	// Vectors for all of the tracks (save for the individual holding track(s), which are created in generate())
	vector<int> inputVect, outputVect;
	vector<vector<int>> holdingVects;
	int numCars;

	// Checks for any car on a given track with a smaller number than that of the given car
	bool smallestTrack(int compVal, vector<int> compVect) {
		if (compVect.empty()) { return true; }
		for (int i = 0; i < inputVect.size(); ++i) {
			if (compVal > inputVect.at(i)) {
				// Returns false the moment a smaller number is found
				return false;
			}
		}
		// Assumed true unless proven otherwise
		return true;
	}

	// Checks for any last car on any of the holding tracks with a smaller number than that of the given car
	bool smallestHeld(int compVal, vector<vector<int>> compVects) {
		for (int i = 0; i < compVects.size(); ++i) {
			if (!compVects.at(i).empty() && compVal >= compVects.at(i).back()) { return false; }
		}
		// Assumed true unless proven otherwise
		return true;
	}

	// Checks for any car not yet on the output track with a smaller number than that of the given car
	// Uses smallestTrack() and smallestHeld() in tandem
	bool smallestLeft(int compVal) {
		if (smallestTrack(compVal, inputVect) && smallestHeld(compVal, holdingVects)) {
			return true;
		}
		else { return false; } // Assumed false unless proven otherwise
	}
};