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
#include "Dog.h"

using namespace std;

void displayDogs(set<Dog> s) {
	set<Dog> ::iterator itr;

	for (itr = s.begin(); itr != s.end(); ++itr) {
		cout << "   " << *itr;
	}
	cout << endl;
}

//*******************NEW  ERASEBREED FUNCTION **************************************//
void eraseBreed(set<Dog>& d, const string breed) {
	//for (auto it{ d.begin() }, end{ d.end() }; it != end; ) {
	for (auto it = d.cbegin(); it != d.cend(); ) {
		if (it->getBreed() == breed) {
			cout << "Erase: " << *it;
			it = d.erase(it);
		}
		else {
			++it;
		}
	}
}

int main()
{
	// empty set container 
	set <Dog> dogs1; // keep sorted in descending order

	// insert elements in random order 
	dogs1.insert(Dog("Guinness", "Wheaten", 9));
	dogs1.insert(Dog("Grimlock", "Lab", 2));
	dogs1.insert(Dog("Optimus", "Bulldog", 5));
	dogs1.insert(Dog("Bailey", "Wheaten", 5));
	dogs1.insert(Dog("Murphy", "Lab", 14));
	dogs1.insert(Dog("Floyd", "Beagle", 12));

	// only one Bailey gets inserted
	dogs1.insert(Dog("Bailey", "Wheaten", 5));

	// display dogs
	cout << "\ndogs1: \n";
	displayDogs(dogs1);

	// assigning the elements from dogs to dogs2
	set <Dog> dogs2(dogs1.begin(), dogs1.end());

	// display s2 
	cout << "\ndogs2: \n";
	displayDogs(dogs2);

	//// remove all elements up to Guinness in dogs2
	cout << "\ndogs2 after removal of elements less than Guinness: \n";
	string key1 = "Guinness";
	dogs2.erase(dogs2.begin(), dogs2.find(key1));
	displayDogs(dogs2);

	//*******************NEW SET DIFFERENCE**************************************//
	set<Dog> dogs3;

	set_difference(dogs1.begin(), dogs1.end(), dogs2.begin(), dogs2.end(),
					inserter(dogs3, dogs3.end()));

	cout << "\ndogs3 set_difference (dogs2 dogs1): \n";
	//cout << *dogs3.begin(); // will print 3
	displayDogs(dogs3);

	//*******************NEW ERASE **************************************//
	// remove element with value Murphy in dogs2
	string key2 = "Murphy";
	dogs2.erase(key2);
	cout << "\ndogs2 after Murphy removed: \n";
	displayDogs(dogs2);

	eraseBreed(dogs1, "Wheaten");
	cout << "\ndogs1 after Wheaten removed: \n";
	displayDogs(dogs1);

	cin.get();
	return 0;
}
