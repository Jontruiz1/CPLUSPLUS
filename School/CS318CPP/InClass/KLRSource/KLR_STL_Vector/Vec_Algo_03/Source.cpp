//Vec_Algo_03
//	Demos lower_bound, upper_bound
#include <iostream> 
#include <vector> 
#include <algorithm>
using namespace std;

int main()
{
	vector<int> v = { 5, 10, 15, 20, 20, 23, 20, 42, 45 };

	// Sort the array to make sure that lower_bound() and upper_bound() work. 
	sort(v.begin(), v.end());
	cout << "\nVector after sorting in ascending order is: ";
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << " ";
	cout << endl;

	int value = 20;
	//int value = 42;

	// Returns the first occurrence of value 
	auto q = lower_bound(v.begin(), v.end(), value);

	// Returns the last occurrence of value 
	auto p = upper_bound(v.begin(), v.end(), value);

	cout << "\nThe lower bound is at position: " << q - v.begin() << endl;

	cout << "\nThe upper bound is at position: " << p - v.begin() << endl;

	return 0;
}
