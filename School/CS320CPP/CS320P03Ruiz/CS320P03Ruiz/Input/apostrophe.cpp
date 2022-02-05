#include <iostream>
using namespace std;
int main() {
	char testA = 'a';
	char testB = 'b';
	string testS = "";
	int count = 0;
	while (count < 10) {
		testS += testA;
		testS += testB;
		count++;
	}
	cout << testS;
}