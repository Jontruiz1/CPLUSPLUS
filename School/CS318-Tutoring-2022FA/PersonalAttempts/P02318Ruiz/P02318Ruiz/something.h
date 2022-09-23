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
	

}

void getGuesses(vector<int>& answerVec, int maxDigits) {



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

