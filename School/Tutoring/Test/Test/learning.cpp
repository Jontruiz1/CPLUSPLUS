#include <iostream>
#include <string>
#include <stack>          // std::stack

using namespace std;

int main() {
	stack<int> help;
	help.push(1);
	help.push(2);
	help.push(3);

	stack<int> second;
	second.push(4);
	second.push(5);
	second.push(6);

	stack<int> arr[2] = { help, second };

	cout << arr[0].top();


}