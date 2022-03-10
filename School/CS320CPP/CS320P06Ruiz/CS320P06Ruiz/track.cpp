#include "track.h"

void Track::read(istream& in) {
	int a;

	while (in >> a) {
		track.push_back(a);
	}
}

void Track::print(ostream& out) {
	for (auto a : track) {
		out << a;
	}
	out;
}