#include <iostream>
#include "track.h"

using namespace std;

int main() {
	Track inTrack;
	int cars;
	int tracks;

	cout << "Enter number of cars: ";
	cin >> cars;
	cout << endl;

	cout << "Enter number of holding tracks: ";
	cin >> tracks;
	cout << endl;
	
	cout << "Enter car sequence of input track: ";
	cin >> inTrack;

	cout << inTrack;

}