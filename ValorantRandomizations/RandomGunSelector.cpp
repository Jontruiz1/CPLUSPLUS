#include <iostream>
#include <string>

using namespace std;

int main() {

	string primary[] = { "Vandal", "Phantom", "Bulldog", "Stinger", "Spectre", "Odin", "Operator", "Marshall", "Bucky", "Judge", "Guardian", "Ares"};
	string secondary[] = {"Classic", "Frenzy", "Ghost", "Shorty", "Sheriff"};
	const int PRIMARIES = 12;
	const int SECONDARIES = 5;
	srand(time(NULL));

	cout << "Pick " << primary[rand() % PRIMARIES] << " as your primary and " << secondary[rand() % SECONDARIES] << " as your secondary";

}