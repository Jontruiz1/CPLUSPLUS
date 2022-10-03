// KLR_Functors:BO01_Functor_Breakout  BO01_Functor_Breakout.cpp

// Finish the templated class called WackyMath that has private variables x and y;
//  a constructor that sets the values of x and y
//  and the overloaded () operator that multiplies an elem of type T by x and then
//  applies the modulus operator (%y) and returns the result

#include <iostream>
#include <algorithm>
#include <functional>
#include <set>
#include <vector>
#include <iterator>

using namespace std;

template <typename T>
class WackyMath {
    // FINISH
};

// Note:  may need to use bind on some of the following code segments

int main() {
    using namespace std::placeholders;
    vector<int> v{ 5, 1, 17, 20, 25, 30 };
    vector<int> v2;

    cout << "\nOriginal vector v:  ";
    copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
    cout << endl;


    // WRITE THE CODE //
    //  Multiply all ints in vector v by themselves and stores the result
    //  in vector v2.

    cout << "\nNew vector v2 -- after multiplying v elements by themselves: ";
    copy(v2.begin(), v2.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    // WRITE THE CODE //
    //  Multiply all ints in vector v by 3 and store back in v



    cout << "\nVector v -- after multiplying each element by 3: ";
    copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    // WRITE THE CODE //
    //  Divide all ints in vector v by 3 and store back in v


    cout << "\nVector v -- after dividing each element by 3: ";
    copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    // WRITE THE CODE //
    //  Apply modulus (%10) to each elem of v and store in v2

    cout << "\nVector v2 -- after applying %10 to each element: ";
    copy(v2.begin(), v2.end(), ostream_iterator<int>(cout, " "));
    cout << endl;


    // WRITE THE CODE //
    // Declare a WackyMath function object that takes the arguments (2,5);

    // WRITE THE CODE //
    // Apply the function object (functor) declared above to elements in v2
    //  and store back in v2

    cout << "\nVector v2 -- after applying WackyMath functor with arguments 2,5 to each element: ";
    copy(v2.begin(), v2.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    return 0;
}