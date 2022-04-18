// P09Statistics
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>
#include <cmath>
#include <string>
#include <vector>
using namespace std;

void fillVector(ifstream& inFile, vector<double>& v);
void selectionSort(vector<double>& v);
double meanAverage(const vector<double>& v);
double standardDeviation(const vector<double>& v, const double mean);
double medianAverage(const vector<double>& v);

int main() {
	ifstream inputFile;
	string fileName;
	double meanAvg;
	double stdDeviation;
	double median;
	vector <double> stats;
	int numberCount = 0;

	const int MAX_NUMBERS = 20;

	cout << "\n*************** Statistics *************\n" << endl;
	// Prompt for file name
	cout << "Please enter a file name (quit to end): ";
	cin >> fileName;

	while (fileName != "quit") {
		// Open the fileName entered
		inputFile.open(fileName);

		// If file open successfully, then continue
		if (inputFile.fail()) {
			cout << "\n**Error: Cannot open file " << fileName << endl;
		}
		else {
			stats.clear();
			fillVector(inputFile, stats);  //fill vector with numbers from file
			inputFile.close();

			numberCount = stats.size(); //count of numbers read from file

			// Process based on how many numbers were read
			if (numberCount == 0) {
				cout << "\n**Error: File " << fileName << " is an empty file." << endl;
			}
			else if (numberCount > MAX_NUMBERS) {
				cout << "\n**Error: File " << fileName << " exceeds limit of " << MAX_NUMBERS << endl;
			}
			else {
				meanAvg = meanAverage(stats);
				stdDeviation = standardDeviation(stats, meanAvg);
				selectionSort(stats);
				median = medianAverage(stats);

				cout << fixed << showpoint << setprecision(3); // set output formatting

				// Display results
				cout << "\n\tAverage of " << numberCount << " numbers is " << meanAvg << endl;
				cout << "\tStandard deviation of " << numberCount << " numbers is " << stdDeviation << endl;
				cout << "\tMedian of " << numberCount << " numbers is " << median << endl;
			}
		}

		cout << "\n\nPlease enter a file name (quit to end): ";
		cin >> fileName;
	}

	return 0;
}

void fillVector(ifstream& inFile, vector<double>& v) {
	double number;

	while ((inFile >> ws) && (!inFile.eof())) {
		inFile >> number;
		v.push_back(number);
	}
}

void selectionSort(vector<double>& v) {
	for (int i = 0; i < v.size() - 1; i++) {
		int min = i;
		for (int j = i + 1; j < v.size(); j++)
			if (v[j] < v[min])
				min = j;
		//swap
		double t = v[i];
		v[i] = v[min];
		v[min] = t;
	}
}

double meanAverage(const vector<double>& v) {
	double sum = 0;

	if (v.size() == 1) {
		return v.at(0);
	}
	else {
		double sum = 0.0;
		for (int i = 0; i < v.size(); i++) {
			sum += v.at(i);
		}
		return (sum / v.size());
	}
}

double standardDeviation(const vector<double>& v, const double mean) {
	if (v.size() == 1)
		return 0.0;
	else {
		double sum = 0.0; // clear to compute standard deviation
		for (int i = 0; i < v.size(); i++) {
			sum += pow((v.at(i) - mean), 2);
		}

		return (sqrt(sum / (v.size() - 1)));
	}
}

double medianAverage(const vector<double>& v) {
	double median;
	int vectSize = v.size();

	if ((v.size() % 2) == 0) {
		median = (v.at((vectSize / 2) - 1) + v.at(vectSize / 2)) / 2;
	}
	else {
		median = v.at(vectSize / 2);
	}

	return (median);
}

