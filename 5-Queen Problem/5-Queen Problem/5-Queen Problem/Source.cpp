#include <iostream>
#include <vector>

using namespace std;
int main() {
	const int BOARD_SIZE = 5;
	int sum = 0;
	vector<int> board(BOARD_SIZE);

	cout << "Enter a 5 digit number delimited by spaces: " << endl;
	for (int i = 0; i < BOARD_SIZE; ++i) {
		cin >> board[i];
	}

	for (int i = 0; i < BOARD_SIZE; ++i) {
		for (int j = i+1; j < BOARD_SIZE; ++j) {
			if (board[i] == board[j] || board[i] == (board[j]-1)) {
				++sum;
			}
		}
	
}