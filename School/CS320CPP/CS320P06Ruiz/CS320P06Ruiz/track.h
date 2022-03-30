#ifndef __TRACK__
#define __TRACK__

#include <vector>
#include <istream>
#include <iostream>
#include <stack>
#include <string>

using namespace std;


class Track {
private:
	vector<int> input;
	vector<int> output;
	vector<stack<int>> holdingTracks;
	int cars;
	int tracks;
	int max = INT_MIN;
	int curr = 0;
	string moves = "";

public:
	Track(int cars, int tracks);
	void read(istream& in);
	void print(ostream& out);
	bool containsNext(vector<stack<int>>& holdingTracks, int curr, int& i);
	bool findSolution();

};

ostream& operator<<(ostream& out, Track& rhs);
istream& operator>>(istream& in, Track& rhs);
#endif
