// CPP program to demonstrate working of STL stack 
#include <iostream>
#include <stack>
#include "Dog.h"

using namespace std;

void displayStack(stack <Dog> s) {
	cout << "\nDog Stack: " << endl;
	while (!s.empty()) {
		cout << "   " << s.top();
		s.pop();
	}
}

int main()
{
	stack <Dog> s;

	s.push(Dog("Bailey", "Wheaten", 5));
	s.push(Dog("Murphy", "Lab", 14));
	s.push(Dog("Floyd", "Beagle", 12));
	s.push(Dog("Guinness", "Wheaten", 9));
	s.push(Dog("Grimlock", "Lab", 2));
	s.push(Dog("Optimus", "Bulldog", 5));

	displayStack(s);

	cout << "\ns.size(): " << s.size() << endl;
	cout << "\ns.top(): " << s.top();
	cout << "\ns.pop(): " << endl;
	s.pop();

	displayStack(s);

	return 0;
}
