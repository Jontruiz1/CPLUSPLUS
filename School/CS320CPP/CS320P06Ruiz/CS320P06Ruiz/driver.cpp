#include <iostream>
#include "track.h"

using namespace std;

int main() {
	
	int cars;
	int tracks;

	cout << "Enter number of cars: ";
	cin >> cars;
	cout << endl;

	cout << "Enter number of holding tracks: ";
	cin >> tracks;
	cout << endl;

	Track inTrack(cars, tracks);
	inTrack.read();

	cout << inTrack;

}