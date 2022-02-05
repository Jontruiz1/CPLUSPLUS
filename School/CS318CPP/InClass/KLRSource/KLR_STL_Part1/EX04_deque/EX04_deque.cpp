// deque Demo
#include <iostream> 
#include <deque> 

using namespace std;

void displayDeque(deque <int> g) {
	deque <int> ::iterator it;
	for (it = g.begin(); it != g.end(); ++it)
		cout << " " << *it;
}

int main()
{
	deque <int> dq;
	dq.push_back(10);
	dq.push_front(20);
	dq.push_back(30);
	dq.push_front(15);
	cout << "\nContents of dq: ";
	displayDeque(dq);

	cout << "\ndq.size(): " << dq.size();
	cout << "\ndq.max_size(): " << dq.max_size();

	cout << "\ndq.at(2): " << dq.at(2);
	cout << "\ndq.front(): " << dq.front();
	cout << "\ndq.back(): " << dq.back();

	cout << "\ndq.pop_front(): ";
	dq.pop_front();
	cout << "\nContents of dq: ";
	displayDeque(dq);

	cout << "\ndq.pop_back(): ";
	dq.pop_back();
	cout << "\nContents of dq: ";
	displayDeque(dq);

	cout << endl;

	return 0;
}
