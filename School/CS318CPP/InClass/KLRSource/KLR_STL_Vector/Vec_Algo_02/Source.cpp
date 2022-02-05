// Vec_Algo_02
//   Demos the following algorithms: count, find
#include <algorithm> 
#include <iostream> 
#include <vector> 
using namespace std;

int main()
{
	// Initializing vector list of values
	vector<int> v = { 25, 2, 27, 43, 18, 2 };

    cout << "\nOccurrences of 2 in vector : ";

    // Counts the occurrences of 2 
    cout << count(v.begin(), v.end(), 2);
    cout << endl;

    // find() returns iterator to last address, v.end, if element not present 
    int value = 13;
    // use of ternary operator () ? : 
    find(v.begin(), v.end(), value) != v.end() ? 
        cout << "\nElement with value " << value << " found" :
        cout << "\nElement with value " << value << " not found";

	cin.get();

	return 0;
}
