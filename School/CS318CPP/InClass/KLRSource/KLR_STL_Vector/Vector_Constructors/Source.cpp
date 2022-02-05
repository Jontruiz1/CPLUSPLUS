//Vector_Constructors
#include <iostream>
#include <vector>

using namespace std;

int main(void) {

	//default constructor
	cout << "\nConstruct of vector of zero length";
	vector<int> v1;
	cout << "\nSize of v1 = " << v1.size() << endl;

	//fill constructor
	cout << "\nConstruct of vector of specified length and initialize each element";
	vector<int> v2(10, 78);
	cout << "\nValues in v2: " << endl;
	for (int i = 0; i < v2.size(); ++i)
		cout << '\t' << v2[i] << endl;

	//range constructor
	cout << "\nConstruct a vector from another vector";
	vector<int> v3(5, 3);

	/* assign values to vector v3 */
	for (int i = 0; i < v3.size(); ++i)
		v3[i] = i * 2;

	/* create a range constructor v4 from v3 */
	vector<int> v4(v3.begin(), v3.end());

	for (int i = 0; i < v4.size(); ++i)
		cout << v4[i] << endl;

	cin.get();
	return 0;
}