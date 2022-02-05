// Vec_Algo_04
//	Demo erase, erase(unique ...
#include <algorithm> 
#include <iostream> 
#include <vector> 
using namespace std;

int main()
{
	// Initializing vector with array values 
	vector<int> v = { 25, 2, 27, 43, 18, 2, 18 };

	cout << "Vector is: ";
	for (const auto& i : v)
		cout << i << ' ';
	cout << endl;

	// Delete second element of vector 
	v.erase(v.begin() + 1);
	cout << "\nVector after erasing the second element: ";
	for (const auto& i : v)
		cout << i << ' ';
	cout << endl;

	// sorting v to demo unique
	sort(v.begin(), v.end());

	cout << "\nVector sorted:  ";
	for (const auto& i : v)
		cout << i << ' ';
	cout << endl;

	// Deletes the duplicate occurrences 
	v.erase(unique(v.begin(), v.end()), v.end());

	cout << "\nVector after deleting duplicates: ";
	for (const auto& i : v)
		cout << i << ' ';
	cout << endl;

	return 0;
}
