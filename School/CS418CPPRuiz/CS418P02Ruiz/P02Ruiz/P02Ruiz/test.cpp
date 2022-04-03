#include <iostream>
#include <queue>

using namespace std;

int main() {
	
	priority_queue<int> test;
	test.push(1);
	test.push(3);
	test.push(2);

	while (!test.empty()) {
		cout << test.top();
		test.pop();
	}

}