#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;


vector<int> generateAnswer(int maxDigits) {
	vector<int> answer;
	int currRand;

	while (answer.size() < 4) {
		currRand = rand() % 10;
		if (find(answer.begin(), answer.end(), currRand) == answer.end()) {
			answer.push_back(currRand);
		}
	}

	return answer;
}


void getValidGuess(int maxDigits, vector<int>& guessVec){
	string guess;
	cout << "Enter guess: ";
	cin >> guess;

	if (guess.size() > maxDigits || guess.size() < maxDigits) {
		cout << "Error: Guess must be " << maxDigits << "digits -- try again!";
	}
	else if (!hasOnlyDigits(guess)) {
		cout << "Error: Guess can only contain digits -- try again!";
	}
	else {
		for (char& i : guess) {
			guessVec.push_back(i - '0');
		}

		if (!isUnique(guessVec)) {
			cout << "Error: Digits can not be repeated -- try again!" << endl;
		}
	}
}



void getGuesses(vector<int>& answerVec, int maxDigits) {
	int bulls = 0;
	int cows = 0;
	
	int count = 1;
	vector<int> guessVec;
	while (bulls != maxDigits) {
		bulls = 0;
		cows = 0;

		getValidGuess(maxDigits, guessVec);

		if (guessVec.size() < maxDigits) {
			for (int i = 0; i < maxDigits; ++i) {
				for (int j = 0; j < maxDigits; ++j) {
					if (guessVec[i] == answerVec[j]) {
						if (i == j) {
							++bulls;
						}
						else {
							++cows;
						}
						break;
					}
				}
			}

			cout << "\tGuess #" << count++ << ": " << "Bulls " << bulls << " Cows " << cows << endl << endl;
			guessVec.clear();
		}
		
	}
	

}

bool hasOnlyDigits(const string s) {

	for (auto i : s) {
		if (!isdigit(i)) return false;
	}

	return true;
}

bool isUnique(const vector<int>& v) {
	vector<int> curr = v;
	sort(curr.begin(), curr.end());
	auto it = unique(curr.begin(), curr.end());
	if (it != curr.end()) {
		return false;
	}


	return true;
}

