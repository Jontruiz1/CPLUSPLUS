#include <iostream>
#include <string>

using namespace std;

int main() {

	string primary[] = { "Vandal", "Phantom", "Bulldog", "Stinger", "Spectre", "Odin", "Operator", "Marshall", "Bucky", "Judge", "Guardian", "Ares"};
	string secondary[] = {"Classic", "Frenzy", "Ghost", "Shorty", "Sheriff"};
	srand(time(NULL));

	cout << "Pick " << primary[rand() % 12] << " as your primary and " << secondary[rand() % 5] << " as your secondary";

}