#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool is_in_vec(const int& a, const vector<int>& num_to_guess) {
	for (auto i : num_to_guess) {
		if (i == a) return true;
	}
	return false;
}
bool all_ints(string guess) {
	for (const char& i : guess) {
		if (!isdigit(i)) return false;
	}
	return true;
}

vector<int> guess_to_int(string guess) {
	vector<int> result;
	for (const char& i : guess) {
		result.push_back(stoi(to_string(i - '0')));
	}
	return result;
}
bool is_unique()



int main() {
	srand(time(NULL));
	vector<int> num_to_guess;
	vector<int> guess_vec;
	bool won = false;
	int curr;
	string guess;
	int guess_num = 1;
	int bulls = 0;
	int cows = 0;
	
	while (num_to_guess.size() < 4) {
		curr = rand() % 9;
		if (!is_in_vec(curr, num_to_guess)) {
			num_to_guess.push_back(curr);
		}
	}
	

	cout << "Number to Guess is ";
	for (int i : num_to_guess) {
		cout << i;
	}
	cout << endl;

	while (!won) {
		bulls = 0;
		cows = 0;
		cout << "Enter guess -- 4 non-repeating digits (for example 4567): ";
		cin >> guess;
		guess_vec = guess_to_int(guess);
		
		for (int i = 0; i < num_to_guess.size(); i++) {
			for (int j = 0; j < num_to_guess.size(); j++) {
				if (num_to_guess[i] == guess_vec[j]) {
					if (i == j) {
						bulls++;
					}
					else {
						cows++;
					}
				}
			}
		}
		//cout << (guess_vec.size() > 4 || guess_vec.size() < 4) ? "NOt right size" : "";

		cout << "Guess #" << guess_num << ":" << "Bulls " << bulls << " Cows " << cows << endl;
		if (bulls == 4) {
			cout << "Win";
			break;
		}
		guess_num++;
	}
	

}