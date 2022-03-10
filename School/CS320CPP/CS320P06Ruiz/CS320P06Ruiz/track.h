#ifndef __TRACK__
#define __TRACK__

#include <vector>
#include <istream>
#include <iostream>

using namespace std;


class Track {
private:
	vector<int> track;

public:
	void read(istream& in);
	void print(ostream& out);
	istream& operator>>(istream& in);
};

istream& Track::operator>>(istream& in) {

}

#endif __TRACK__