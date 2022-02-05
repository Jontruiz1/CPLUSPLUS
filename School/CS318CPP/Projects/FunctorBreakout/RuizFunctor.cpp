#include <iostream>
#include <algorithm>
#include <functional>
#include <set>
#include <vector>
#include <iterator>

using namespace std;

// fINISH the templated class called WackyMath that has private variables x and y;
//  a constructor that sets the values of x and y
//  and the overloaded () operator that multiplies an elem of type T by x and then
//  applies the modulus operator (%y) and returns the result
template <typename T>
class WackyMath {
    // FINISH
private:
    T x;
    T y;
public:
    WackyMath(T a, T b) {
        x = a;
        y = b;
    }
    T operator()(T a) {
        a *= x;
        a %= y;
        return a;
    }

};

// Note:  may need to use bind on some of the following code segments

int main() {
    vector<int> v{ 5, 1, 17, 20, 25, 30 };
    vector<int> v2;

    cout << "\nOriginal vector v:  ";
    copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    //  Multiply all ints in vector v by themselves and stores the result
    //  in vector v2.
    transform(v.begin(), v.end(), v.begin(), v.begin(), multiplies<int>());
    v2 = v;

    cout << "\nNew vector v2 -- after multiplying v elements by themselves: ";
    copy(v2.begin(), v2.end(), ostream_iterator<int>(cout, " "));
    cout << endl;


    //  Multiply all ints in vector v by 3 and store back in v

    transform(v.begin(), v.end(), v.begin(), bind2nd(multiplies<int>(), 3));

    cout << "\nVector v -- after multiplying each element by 3: ";
    copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
    cout << endl;


    //  Divide all ints in vector v by 3 and store back in v

    transform(v.begin(), v.end(), v.begin(), bind2nd(divides<int>(), 3));

    cout << "\nVector v -- after dividing each element by 3: ";
    copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
    cout << endl;


    //  Apply modulus (%10) to each elem of v and store in v2

    transform(v.begin(), v.end(), v2.begin(), bind2nd(modulus<int>(), 10));


    cout << "\nVector v2 -- after applying %10 to each element: ";
    copy(v2.begin(), v2.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    // Declare a WackyMath function object that takes the arguments (2,5);
    WackyMath<int> functr(2, 5);


    // Apply the function object (functor) declared above to elements in v2
    //  and store back in v2
    transform(v2.begin(), v2.end(), v2.begin(), functr);

    cout << "\nVector v2 -- after applying WackyMath functor with arguments 2,5 to each element: ";
    copy(v2.begin(), v2.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    return 0;
}

