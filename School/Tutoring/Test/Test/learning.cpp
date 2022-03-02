#include <iostream>
#include <string>

using namespace std;

int main() {
	string help = "racecar";
	string reverse = "";
	for (auto it = help.crbegin(); it != help.crend(); it++) {
		reverse += *it;
	}

	if (reverse == help) {
		cout << "true";
	}


}