vector<int> answer;
vector<int> guess;

answer = {1, 2, 3, 4}

guess = {2, 1, 3, 4}


for (int i = 0; i < 4; ++i) {
	for (int j = 0; j < 4; ++j) {
		if (answer[i] == guess[j]) {
			if (i == j) {
				bull++
			}
			else {
				cow++
			}
		}
	}
}