//Vector01
//   Demo capacity
/*
size() – Returns the number of elements in the vector.
max_size() – Returns the maximum number of elements that the vector can hold.
capacity() – Returns the size of the storage space currently allocated to 
             the vector expressed as number of elements.
resize(n) – Resizes the container so that it contains ‘n’ elements.
empty() – Returns whether the container is empty.
shrink_to_fit() – Reduces the capacity of the container to fit its size 
                  and destroys all elements beyond the capacity.
reserve() – Requests that the vector capacity be at least enough to contain n elements.
*/

#include <iostream> 
#include <vector> 
#include <string>

using namespace std;

int main()
{
    vector<string> v =
    { "Follow", "the", "yellow", "brick", "road", "to", "the", "Emerald", "City" };

    cout << "Size : " << v.size();
    cout << "\nCapacity : " << v.capacity();
    cout << "\nMax_Size : " << v.max_size();

    // resizes the vector size to 4 
    v.resize(4);

    // prints the vector size after resize() 
    cout << "\nSize : " << v.size();

    // checks if the vector is empty or not 
    if (v.empty() == false)
        cout << "\nVector is not empty";
    else
        cout << "\nVector is empty";

    // Shrinks the vector 
    v.shrink_to_fit();
    cout << "\nVector elements are: ";
    for (auto it = v.begin(); it != v.end(); it++)
        cout << *it << " ";

    return 0;
}
