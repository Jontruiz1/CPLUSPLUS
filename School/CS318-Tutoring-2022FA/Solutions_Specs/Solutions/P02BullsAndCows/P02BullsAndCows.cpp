// P02BullsAndCows
#include <iostream>
#include <vector>
#include <string>
#include <time.h>
#include <algorithm>
#include <set>
using namespace std;

bool hasOnlyDigits(const string s);
bool isUniqueBoolArray(const vector<int>& v);
bool isUniqueSet(const vector<int>& v);
bool isUniqueLoop(const vector<int>& v);
bool isUniqueFind(const vector<int>& v);
vector<int> generateAnswerRand(int maxDigits);
vector<int> generateAnswerShuffle(int maxDigits);

int main() {

	const int maxDigits = 4;
	string guess;
	string answer;
	int bulls = 0;
	int cows = 0;
	int guessCount = 0;
	char choice;
	vector<int> guessVec;

	do {
		bulls = 0;
		cows = 0;

		//vector<int> answerVec = generateAnswerRand(maxDigits);
		vector<int> answerVec = generateAnswerShuffle(maxDigits);

		cout << "\n  Number to Guess is ";
		for (int i = 0; i < answerVec.size(); i++)
			cout << answerVec.at(i);
		cout << endl;

		while (bulls != maxDigits) {
			bulls = 0;
			cows = 0;
			guessCount = 0;

			cout << "\n  Enter guess -- 4 non-repeating digits (for example 4567):  ";
			getline(cin, guess);
			guessCount++;

			if (guess.length() == maxDigits && hasOnlyDigits(guess)) {

				// build guess vector from input string
				for (int i = 0; i < guess.length(); i++)
					guessVec.push_back(guess.at(i) - '0');

				// if numbers unique count bulls and cows
				if (isUniqueSet(guessVec)) {
					for (int i = 0; i < guessVec.size(); i++) {
						for (int j = 0; j < guessVec.size(); j++) {
							if (answerVec[j] == guessVec[i])
								if (i == j)
									bulls++;
								else
									cows++;
						}
					}
				}
				else {
					cout << "  Error:  Digits can not be repeated" << endl;
				}
			}
			else {
				cout << "  Error:  Guess must be 4 digits" << endl;
			}

			cout << "  Guess #" << guessCount << ": Bulls " << bulls << " Cows " << cows << "\n";

			guessVec.clear();
		}

		cout << "\n  *** YOU WIN! ***\n";

		cout << "\n\n Enter Y to play again (anything else to end): ";
		cin >> choice;
		// clear buffer
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	} while (tolower(choice) == 'y');

	return 0;
} //end main

vector<int> generateAnswerRand(int maxDigits) {
	vector<int> v;

	do {
		v.clear();
		srand(time(0));
		for (int i = 0; i < maxDigits; i++)
			v.push_back(rand() % 10);
	} while (!isUniqueFind(v));

	return v;
}

vector<int> generateAnswerShuffle(int maxDigits) {
	vector<int> v;

	for (int i = 0; i < 10; i++) { v.push_back(i); }

	srand(time(0));
	random_shuffle(v.begin(), v.end());

	v.resize(maxDigits);

	return v;
}


bool hasOnlyDigits(const string s) {
	return s.find_first_not_of("0123456789") == string::npos;
}

bool isUniqueBoolArray(const vector<int>& v) {
	bool number[10] = { false };

	for (int i = 0; i < v.size(); i++) {
		if (number[v.at(i)])
			return false;
		else
			number[v.at(i)] = true;
	}
	return true;
}

bool isUniqueSet(const vector<int>& v) {
	set<int> myset;
	set<int>::iterator it;
	pair<set<int>::iterator, bool> ret;

	for (int i = 0; i < v.size(); i++) {
		ret = myset.insert(v.at(i));
		if (ret.second == false)
			return false; //element already in set -- duplicate
	}
	return true;
}

bool isUniqueLoop(const vector<int>& v) {
	for (int i = 0; i < v.size(); i++) {
		char current = v.at(i);
		for (int j = i + 1; j < v.size(); j++) {
			if (current == v.at(j)) {
				return false;
			}
		}
	}
	return true;
}

bool isUniqueFind(const vector<int>& v) {
	for (int i = 0; i < v.size(); i++) {
		if (find(v.begin(), v.end(), v.at(i)) != v.end())
			return false;
	}
	return true;
}