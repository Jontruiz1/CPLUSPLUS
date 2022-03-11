#ifndef __TRACK__
#define __TRACK__

#include <vector>
#include <istream>
#include <iostream>

using namespace std;


class Track {
private:
	vector<int> track;
	int cars;
	int holdingTracks;

public:
	Track(int cars, int tracks);
	void read();
	void print(ostream& out);
};

ostream& operator<<(ostream& out, Track& rhs);
#endif
