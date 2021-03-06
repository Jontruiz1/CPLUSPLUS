/*
	Jonathan Ruiz
	Bulls and Cows
*/

#include <iostream>;
#include <vector>;
#include <string>;
#include <time.h>;

using namespace std;
const int maxlength = { 4 };

int main() {
	int count = { 1 };
	int bulls, cows, intguess = { 0 };

	string strGuess = "";
	string choice = "";
	string printVect;
	vector<int> guess;
	vector<int> numToGuess;

	vector<int> createVect();
	bool isUnique(vector<int> guess);
	bool isDigits(string guess);
	void displayVect(vector<int> numToGuess, string printVect);

	numToGuess = createVect();
	displayVect(numToGuess, printVect);

	do {
		bulls = { 0 };
		cows = { 0 };
		guess.clear();

		cout << "Enter guess -- 4 non-repeating digits (for example 4567): ";
		cin >> strGuess;

		//checks if its a digit
		if (!isDigits(strGuess)) {
			cout << "Error: Guess must be 4 digits" << endl;
			cout << "Guess #" << count << ": Bulls: " << bulls << " Cows: " << cows << endl << endl;
			count++;
			continue;
		}
		//converts string guess into a int vector
		for (int i = 0; i < strGuess.length(); i++) {
			intguess = strGuess.at(i) - 48;
			guess.push_back(intguess);
		}

		//checks if there are duplicates
		if (!isUnique(guess)) {
			cout << "Error: Digits cannot be repeated" << endl;
		}
		else {
			//cow and bull count if there are no duplicates
			for (int i = 0; i < guess.size(); i++) {
				if (numToGuess.at(i) == guess.at(i)) {
					bulls++;
				}
				if ((find(numToGuess.begin(), numToGuess.end(), guess.at(i)) != numToGuess.end()) && (guess.at(i) != numToGuess.at(i))) {
					cows++;
				}
			}
		}

		cout << "Guess #" << count << ": Bulls: " << bulls << " Cows: " << cows << endl << endl;
		count++;
		//asks if you want to play again
		if (bulls == 4) {
			cout << "*** YOU WIN! ***\nPlay again?(y/n): ";
			cin >> choice;
			cout << endl;

			if (choice == "y") {
				bulls = { 0 };
				cows = { 0 };
				count = { 1 };
				//creates a new vector and then displays it
				numToGuess = createVect();
				displayVect(numToGuess, printVect);
			}
		}
	} while (bulls != 4);
}

//creates the random int vector
vector<int> createVect() {

	int randNum = { 0 };
	vector<int> numToGuess;
	srand(time(NULL));

	for (int i = 0; i < maxlength; i++) {
		randNum = rand() % 10;
		while (true) {
			if (find(numToGuess.begin(), numToGuess.end(), randNum) != numToGuess.end()) {
				randNum = rand() % 10;
			}
			else {
				numToGuess.push_back(randNum);
				break;
			}
		}
	}
	return numToGuess;
}

//checks for duplicates;
bool isUnique(vector<int> guess) {
	for (int i = 0; i < guess.size() - 1; i++) {
		if (guess.at(i) == guess.at(i + 1)) {
			return false;
		}
	}
	return true;

}

//checks if the guess is only digits and if the length is 4
bool isDigits(string guess) {
	if (guess.length() > maxlength || guess.length() < maxlength) {
		return false;
	}
	else {
		for (int i = 0; i < guess.length(); i++) {
			if (!isdigit(guess.at(i))) {
				return false;
			}
		}
		return true;
	}
}

//displays the random vector
void displayVect(vector<int> numToGuess, string printVect) {
	for (int i = 0; i < numToGuess.size(); i++) {
		printVect += to_string(numToGuess.at(i));
	}
	cout << "Number to Guess is " << printVect << endl << endl;
}
