// list demo
#include <iostream> 
#include <list> 
#include <iterator> 
using namespace std;

void displayList(list <int> lst)
{
	list <int> ::iterator it;
	for (it = lst.begin(); it != lst.end(); ++it)
		cout << ' ' << *it;
	cout << '\n';
}

int main()
{
	list <int> list1, list2;

	for (int i = 0; i < 5; ++i) {
		list1.push_back(i * 2);
		list2.push_front(i * 3);
	}

	cout << "\nlist1: ";
	displayList(list1);

	cout << "\nlist2: ";
	displayList(list2);

	cout << "\nlist1.front(): " << list1.front() << endl;
	cout << "\nlist1.back(): " << list1.back() << endl;

	cout << "\nlist1.pop_front(): ";
	list1.pop_front();
	displayList(list1);

	cout << "\nlist2.pop_back(): ";
	list2.pop_back();
	displayList(list2);

	cout << "\nlist1.reverse(): ";
	list1.reverse();
	displayList(list1);

	cout << "\nlist2.sort(): ";
	list2.sort();
	displayList(list2);

	return 0;

}
