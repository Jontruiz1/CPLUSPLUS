//Vector02
//  Demo element access
/*
	reference operator [g] – Returns a reference to the element at 
	                         position ‘g’ in the vector
	at(g) – Returns a reference to the element at position ‘g’ in the vector
	front() – Returns a reference to the first element in the vector
	back() – Returns a reference to the last element in the vector
	data() – Returns a direct pointer to the memory array used internally 
	         by the vector to store its owned elements.
*/

#include <iostream> 
#include <vector> 
#include <string>
using namespace std;

int main()
{
    vector<string> v =
    { "Follow", "the", "yellow", "brick", "road", "to", "the", "Emerald", "City" };

    cout << "\nReference operator [g] : v[2] = " << v[2];

    cout << "\nat : v.at(4) = " << v.at(4);

    cout << "\nfront() : v.front() = " << v.front();

    cout << "\nback() : v.back() = " << v.back();

    // pointer to the first element 
    string* pos = v.data();

    cout << "\nThe first element is " << *pos;
    return 0;
}
