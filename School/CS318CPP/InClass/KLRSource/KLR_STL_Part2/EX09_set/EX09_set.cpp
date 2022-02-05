// set Demo
/*
	The declaration of std::set looks like this:

	template<
		class Key,
		class Compare = std::less<Key>,
		class Allocator = std::allocator<Key>
	> class set;
*/


#include <iostream> 
#include <set> 
#include <iterator> 

using namespace std;

void displaySet1(set<int, greater <int>> s) {
	set<int> ::iterator itr;

	for (itr = s.begin(); itr != s.end(); ++itr) {
		cout << " " << *itr;
	}
	cout << endl;
}

void displaySet2(set<int> s) {
	set<int> ::iterator itr;

	for (itr = s.begin(); itr != s.end(); ++itr) {
		cout << " " << *itr;
	}
	cout << endl;
}


int main()
{
	// empty set container 
	set <int, greater <int>> s1; // keep sorted in descending order

	// insert elements in random order 
	s1.insert(40);
	s1.insert(30);
	s1.insert(60);
	s1.insert(20);
	s1.insert(50);
	s1.insert(50); //only one 50 will be added to the set 
	s1.insert(10);

	// declaration of iterator
	//set <int, greater <int>> :: iterator itr;
	set<int> :: iterator itr;

	// diplay s1
	cout << "\nset s1: ";
	displaySet1(s1);

	// assigning the elements from s1 to s2 
	// elements in s2 will be ascending order
	set <int> s2(s1.begin(), s1.end());

	// display s2 
	cout << "\nset s2 after assign from s1: ";
	displaySet2(s2);

	// remove all elements up to 30 in s2 
	cout << "\ns2 after removal of elements less than 30: ";
	s2.erase(s2.begin(), s2.find(30));
	displaySet2(s2);

	// remove element with value 50 in s2 
	s2.erase(50);
	cout << "\ns2 after 50 removed: ";
	displaySet2(s2);

	//lower bound and upper bound for set s1 
	cout << "\ns1.lower_bound(40): " << *s1.lower_bound(40) << endl;
	cout << "s1.upper_bound(40 : " << *s1.upper_bound(40) << endl;

	//lower bound and upper bound for set s2 
	cout << "\ns2.lower_bound(40): " << *s2.lower_bound(40) << endl;
	cout << "s2.upper_bound(40): " << *s2.upper_bound(40) << endl;

	return 0;

}
