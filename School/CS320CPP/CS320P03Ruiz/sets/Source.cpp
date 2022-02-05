#include <iostream>
#include <set>

using namespace std;

int main() {

	set<unsigned> tester;
	tester.insert(1);
	tester.insert(2);

	for (auto it = tester.begin(); it != tester.end(); it++) {
		cout << *it;
	}

}