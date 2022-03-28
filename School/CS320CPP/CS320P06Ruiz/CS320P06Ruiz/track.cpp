#include "track.h"

void Track::read(istream& in) {
	cout << "Enter car sequence on input track: ";
	for (int i = 0; i < cars; i++) {
		int temp;
		in >> temp;
		if (temp > max) {
			max = temp;
		}
		input[i] = temp;
	}
}

void Track::print(ostream& out) {
	for (auto a : output) {
		out << a;
	}
}

Track::Track(int cars, int tracks) {
	this->cars = cars;
	this->tracks = tracks;
	input.resize(cars);
	holdingTracks.resize(tracks);
}

ostream& operator<<(ostream& out, Track& rhs) {
	rhs.print(out);
	return out;
}
istream& operator>>(istream& in, Track& rhs) {
	rhs.read(in);
	return in;
}

bool Track::containsNext(vector<stack<int>>& holdingTracks, int curr, int& i) {

	for (stack<int> track : holdingTracks) {
		if (!track.empty() && (track.top() == curr || track.top() == (curr + 1))) {
			return true;
		}
		++i;
	}
	return false;
}

bool Track::findSolution() {
	int i = 0;
	while (curr != (max)) {
		i = 0;
		if (!input.empty() && (input.front() == curr || input.front() == (curr + 1))) {
			cout << "Move car " << input.front() << " from input track to output track\n";
			output.push_back(input.front());
			input.erase(input.begin());
			++curr;
		}
		else if (containsNext(holdingTracks, curr, i)) {
			cout << "Move car " << holdingTracks[i].top() << " from holding track " << i + 1 << " to output track\n";
			output.push_back(holdingTracks[i].top());
			holdingTracks[i].pop();
			++curr;
		}
		else {
			i = 0;
			for (auto track : holdingTracks) {
				if (track.empty() || (track.top() >= input.front())) {
					cout << "Move car " << input.front() << " from input track to holding track " << i + 1 << endl;
					holdingTracks[i].push(input.front());
					input.erase(input.begin());
					break;
				}
				++i;
				if (i == tracks) {
					cout << "No Solution";
					return false;
				}
			}
		}
	}

	return true;
}