// P08SoccerTeam -- SOLUTION
#include <iostream>
#include <vector>
using namespace std;

int main() {

	vector<int> jerseyNums;
	vector<int> ratingNums;

	int i;
	int playerJersey;
	int playerRating;
	char menuOp;

	cout << "*** Soccer Team Roster ***" << endl;

	do {
		cout << "\n--Menu--" << endl;
		cout << "a - Add player" << endl;
		cout << "d - Remove player" << endl;
		cout << "u - Update player rating" << endl;
		cout << "r - Output players above a rating" << endl;
		cout << "o - Output roster" << endl;
		cout << "q - Quit" << endl << endl;

		cout << "Choose an option: ";
		cin >> menuOp;
		cout << endl;

		switch (menuOp) {
		case 'a':  //Add
			cout << "Enter a new player's jersey number: ";
			cin >> playerJersey;

			for (i = 0; i < jerseyNums.size(); ++i) {
				if (playerJersey == jerseyNums.at(i)) {
					break;
				}
			}

			if (i < jerseyNums.size()) {
				cout << "  >>> Jersey number " << playerJersey << " already in use! <<<" << endl;
			}
			else {
				jerseyNums.push_back(playerJersey);
				cout << "Enter the player's rating: ";
				cin >> playerRating;
				ratingNums.push_back(playerRating);
				cout << "  >>> Jersey number " << playerJersey << " added! <<<" << endl;
			}
			break;
		case 'd': //Delete
			cout << "Enter a jersey number: ";
			cin >> playerJersey;

			for (i = 0; i < jerseyNums.size(); ++i) {
				if (playerJersey == jerseyNums.at(i)) {
					break;
				}
			}

			if (i == jerseyNums.size()) {
				cout << "  >>> Jersey number " << playerJersey << " not found! <<<" << endl;
			}
			else {
				jerseyNums.erase(jerseyNums.begin() + i);
				ratingNums.erase(ratingNums.begin() + i);
				cout << "  >>> Jersey number " << playerJersey << " deleted! <<<" << endl;

			}
			break;
		case 'u': //Update
			cout << "Enter a jersey number: ";
			cin >> playerJersey;

			for (i = 0; i < jerseyNums.size(); ++i) {
				if (playerJersey == jerseyNums.at(i)) {
					break;
				}
			}

			if (i == jerseyNums.size()) {
				cout << "  >>> Jersey number " << playerJersey << " not found! <<<" << endl;
			}
			else {
				cout << "Enter a new rating for player: ";
				cin >> playerRating;
				ratingNums.at(i) = playerRating;
				cout << "  >>> Jersey number " << playerJersey << " rating updated! <<<" << endl;
			}
			break;
		case 'r': //Rating
			cout << "Enter a rating: ";
			cin >> playerRating;
			cout << endl;

			cout << "<<< Ranking Above " << playerRating << " >>>" << endl;
			for (i = 0; i < jerseyNums.size(); ++i) {
				if (ratingNums.at(i) > playerRating) {
					cout << "Player " << i + 1 << " -- Jersey number: "
						<< jerseyNums.at(i) << ", Rating: "
						<< ratingNums.at(i) << endl;
				}
			}
			break;
		case 'o': //Output roster
			cout << "<<< Full Roster >>>" << endl;
			for (i = 0; i < jerseyNums.size(); ++i) {
				cout << "Player " << i + 1 << " -- Jersey number: "
					<< jerseyNums.at(i) << ", Rating: "
					<< ratingNums.at(i) << endl;
			}
			break;
		} //end switch
	} while (menuOp != 'q');

	return 0;
}
