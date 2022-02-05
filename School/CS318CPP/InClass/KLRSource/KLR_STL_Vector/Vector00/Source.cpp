//Vector00
// Demo various iterators
/*
*	begin() � Returns an iterator pointing to the first element in the vector
	end() � Returns an iterator pointing to the theoretical element that 
	        follows the last element in the vector
	rbegin() � Returns a reverse iterator pointing to the last element in the vector
	           (reverse beginning). It moves from last to first element
	rend() � Returns a reverse iterator pointing to the theoretical element 
	         preceding the first element in the vector (considered as reverse end)
	cbegin() � Returns a constant iterator pointing to the first element in the vector.
	cend() � Returns a constant iterator pointing to the theoretical element 
	         that follows the last element in the vector.
	crbegin() � Returns a constant reverse iterator pointing to the 
	            last element in the vector (reverse beginning). 
				It moves from last to first element
	crend() � Returns a constant reverse iterator pointing to the 
	          theoretical element preceding the first element in the vector
			  (considered as reverse end)
*/

#include <iostream> 
#include <vector> 

using namespace std;

int main()
{
    vector<int> v;

    for (int i = 1; i <= 10; i++)
        v.push_back(i);

    cout << "Output of begin and end: ";
    for (auto i = v.begin(); i != v.end(); ++i)
        cout << *i << " ";

    cout << "\nOutput of cbegin and cend: ";
    for (auto i = v.cbegin(); i != v.cend(); ++i)
        cout << *i << " ";

    cout << "\nOutput of rbegin and rend: ";
    for (auto ir = v.rbegin(); ir != v.rend(); ++ir)
        cout << *ir << " ";

    cout << "\nOutput of crbegin and crend : ";
    for (auto ir = v.crbegin(); ir != v.crend(); ++ir)
        cout << *ir << " ";

    return 0;
}
