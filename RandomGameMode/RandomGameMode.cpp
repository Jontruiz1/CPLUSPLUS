#include <iostream>

using namespace std;

int main() {
	srand(time(NULL));
	string gamemodes[] = { "Unrated", "Competitive", "Deathmatch", "Escalation"};

	cout << "Pick: " << gamemodes[rand() % 4];

}