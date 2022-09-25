#include "something.h"


int main() {
	vector<int> answerVect;
	vector<int> guessVect;
	srand(time(NULL));
	string playAgain = "y";
	
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
		
		getGuesses(answerVect, MAX_SIZE);
	}
	

}