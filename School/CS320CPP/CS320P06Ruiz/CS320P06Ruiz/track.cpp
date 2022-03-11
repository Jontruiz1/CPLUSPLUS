#include "track.h"

void Track::read() {
	track.resize(cars);

	cout << "Enter car sequence on input track: ";
	for (int i = 0; i < cars; ++i) {
		cin >> track[i];
	}
}

void Track::print(ostream& out) {
	for (auto a : track) {
		out << a;
	}
	out;
}

Track::Track(int cars, int holdingTracks) {
	this->cars = cars;
	this->holdingTracks = holdingTracks;
}

ostream& operator<<(ostream& out, Track& rhs) {
	rhs.print(out);
	return out;
}