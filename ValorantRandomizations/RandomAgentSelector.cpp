#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	vector<string> agents = { "Omen", "Viper", "Phoenix", "Jett", "Cyper", "Skye", "Sova", "Raze", "Brimstone", "Breach", "Yoru", "Reyna", "Sage", "Killjoy", "Astra" , "Harbor", "Fade", "Neon", "KAY/O", "Gekko" };
	vector<string> choices;
	int players;
	srand(time(NULL));

	cout << "How many random agent selections do you want?: ";
	cin >> players;

	while (choices.size() < players) {
		string current = agents[rand() % agents.size()];
		if (find(choices.begin(), choices.end(), current) == choices.end()) choices.push_back(current);
	}

	int i = 1;
	for (string agent : choices) {
		cout << "Player " << i++ <<" choose " << agent << endl;
	}
}