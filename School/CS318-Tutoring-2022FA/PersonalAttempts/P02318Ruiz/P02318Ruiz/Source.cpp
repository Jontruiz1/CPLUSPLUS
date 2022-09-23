#include "something.h"


int main() {
	vector<int> answerVect;
	vector<int> guessVect;
	srand(time(NULL));
	string playAgain = "y";
	string guess;
	int count = 0;
	int cows;
	int bulls;
	const int MAX_SIZE = 4;

	cout << "*** P02 Bulls and Cows ***" << endl << endl;
	answerVect = generateAnswer(MAX_SIZE);
	cout << "Vector to guess: ";
	for (int i : answerVect) {
		cout << i;
	}

	cout << endl;

	while (playAgain == "y") {
		cout << "********** New Game **********" << endl << endl;

		cout << "Guesses entered must be digits 0-9, 4 digits long, no repetition." << endl << endl;

		guessVect.clear();
		bulls = 0;
		cows = 0;
		cout << "Enter guess: ";
		cin >> guess;

		if(guess.size() > answerVect.size() || guess.size() < answerVect.size()){
			cout << "Error: Guess must be " << answerVect.size() << "digits -- try again!";
			continue;
		}
		else if (!hasOnlyDigits(guess)) {
			cout << "Error: Guess can only contain digits -- try again!";
			continue;
		}
		else {
			for (char& i : guess) {
				guessVect.push_back(i - '0');
			}

			if (!isUnique(guessVect)) {
				cout << "Error: Digits can not be repeated -- try again!" << endl;
				continue;
			}
		}

		for (int i = 0; i < MAX_SIZE; ++i) {
			for (int j = 0; j < MAX_SIZE; ++j) {
				if (guessVect[i] == answerVect[j]) {
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


		cout << "\tGuess #" << ++count << ": " << "Bulls " << bulls << " Cows " << cows << endl << endl;

		if (bulls == MAX_SIZE) {
			cout << "*** YOU WIN! ***" << endl << endl;
			cout << "Enter Y to play again (anything else to end): ";
			cin >> playAgain;
			cout << endl;

			if(playAgain == "y") answerVect = generateAnswer(MAX_SIZE);
		}
	}
	

}