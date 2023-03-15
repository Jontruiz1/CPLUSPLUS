#include <iostream>
#include <string>

using namespace std;

int main() {
	string agents[] = { "Omen", "Viper", "Phoenix", "Jett", "Cyper", "Skye", "Sova", "Raze", "Brimstone", "Breach", "Yoru", "Reyna", "Sage", "Killjoy", "Astra" };
	srand(time(NULL));

	cout << "Choose " << agents[rand() % 15];
}