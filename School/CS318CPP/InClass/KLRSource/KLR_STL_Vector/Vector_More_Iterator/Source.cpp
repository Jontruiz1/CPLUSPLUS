//Vector_More_Iterator
// Demo advance, next, prev, inserter

#include<iostream> 
#include<iterator> // for iterators 
#include<vector> // for vectors 
#include<string>
using namespace std;
int main()
{
	// ***** advance() -- increments the iterator the specified number of positions
	vector<string> v = 
		{ "Follow", "the", "yellow", "brick", "road", "to", "the", "Emerald", "City" };

	cout << "Vector is: ";
	for (const auto& i : v)
		cout << i << ' ';
	cout << endl;

	auto vptr = v.begin();

	// Using advance() to increment iterator position to 3 positions forward
	advance(vptr, 3);
	cout << "\nValue of element after advancing iterator 3 positions forward:  " << *vptr << endl;

	// ***** next() -- Returns new iterator by advancing original begin iterator forward            
	// ***** prev() :- Returns new iterator by advancing original end iterator backward

	// Declaring new iterators to a vector begin and end
	auto vbptr = v.begin();
	vector<string>::iterator veptr = v.end();

	// Using next() to return new iterator pointing to v at 5th element 
	auto itnext = next(vbptr, 4);

	// Using prev() to return new iterator pointing to v at 2nd element from end 
	auto itprev = prev(veptr, 2);

	// Displaying iterator position 
	cout << "\nThe position of new iterator using next() is: ";
	cout << *itnext << " ";
	cout << endl;

	// Displaying iterator position 
	cout << "The position of new iterator using prev() is: ";
	cout << *itprev << " ";
	cout << endl;
	
	// ***** inserter() -- Inserts other vector elements at any position in another vector. 
	vector<int> v2 = { 1, 2, 3, 4, 5 };
	vector<int> v3 = { 10, 20, 30 };

	cout << "\nVector v2: ";
	for (int& x : v2)
		cout << x << " ";

	cout << "\nVector v3: ";
	for (int& x : v3)
		cout << x << " ";

	vector<int>::iterator ptr = v2.begin();
	// Advance ptr
	advance(ptr, 3);

	// Copy vector elements into another using inserter() 
	// Insert v3 after 3rd position in v2 
	copy(v3.begin(), v3.end(), inserter(v2, ptr));

	// Displaying new vector elements 
	cout << "\nThe new vector after inserting v3 elements into v2: ";
	for (int& x : v2)
		cout << x << " ";
	cout << endl;

	cin.get();
	
	return 0;
}
