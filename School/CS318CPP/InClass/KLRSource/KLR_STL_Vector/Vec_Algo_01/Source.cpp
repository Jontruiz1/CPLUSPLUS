// Vec_Algo_01
//   Demos the following algorithms: sort, reverse, max_element, min_element, accumulate
#include <algorithm> 
#include <iostream> 
#include <vector> 
#include <numeric> //For accumulate operation 
using namespace std;

int main()
{
	// Initializing vector list of values
	vector<int> v = { 25, 2, 27, 43, 18, 2 };

	cout << "Vector is: ";
	for (const auto& i : v)
		cout << i << ' ';
	cout << endl;

	// Sorting the elements in ascending order 
	sort(v.begin(), v.end());
	cout << "\nVector after sorting in ascending order is: ";
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << " ";
	cout << endl;

	// Sorting the elements in descending order using predicate function
	sort(v.begin(), v.end(), greater <>());
	cout << "\nVector after sorting in descending order is: ";
	for (const auto& i : v)
		cout << i << ' ';
	cout << endl;

	// Reversing the Vector 
	reverse(v.begin(), v.end());

	cout << "\nVector after reversing is: ";
	for (const auto& i : v)
		cout << i << ' ';
	cout << endl;

	cout << "\nMaximum element is: " << *max_element(v.begin(), v.end()) << endl;

	cout << "\nMinimum element is: " << *min_element(v.begin(), v.end()) << endl;

	// Starting the summation from 0 
	cout << "\nSum of vector elements is: " << accumulate(v.begin(), v.end(), 0) << endl;

	cin.get();
	
	return 0;
}
