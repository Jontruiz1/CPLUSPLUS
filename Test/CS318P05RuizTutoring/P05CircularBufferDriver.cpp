// P05CircularBufferDriver.cpp -- starter code

/*  REQUIREMENTS NOTES:

    Fill in the remainder of this driver program.
    Replicate exactly the sample run provided with project's specs.
    Use a capacity of 5

*/
#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
#include "circular_buffer.h"
#include "dog.h"

using namespace std;

int main() {
    cout << "\n*************** <int> Circular Buffer Demo ******************\n";
    //  FINISH THIS SECTION
    cout << "Initial State" << endl;
    CircularBuffer<int, 5> test;
    cout << test;
   
    for (int i = 0; i <= 70; i += 10) {
        cout << "Pushing " << i << endl;
        test.push_back(i);
        cout << test;
    }

    cout << "\n*************** <string> Circular Buffer Demo ******************\n";

    //  FINISH THIS SECTION --
    // create a vector of words
    // use back_insert_iterator to fill the buffer


    cout << "\n*************** <Dog> Circular Buffer Demo ******************\n";

    //  FINISH THIS SECTION

    cout << endl;
}
