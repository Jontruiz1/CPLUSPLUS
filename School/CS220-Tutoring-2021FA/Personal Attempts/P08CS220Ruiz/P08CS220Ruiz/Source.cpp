#include <iostream>
#include <vector>

using namespace std;


string RemoveNonAlpha(string userString) {

	string tmp = "";
	for (int i = 0; i < userString.size(); i++) {

		if ( isalpha( userString.at(i) ) ) {
			tmp += userString.at(i);
		}

	}

	return tmp;
}

int main() {
	string userstring = "-Hello, 1 world$!";
	

	cout << RemoveNonAlpha(userstring);

	return 0;

}