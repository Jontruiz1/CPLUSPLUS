// main.cpp

/*  REQUIREMENTS NOTES:

    Fill in the remainder of this driver program.
    Replicate exactly the sample run provided with project's specs.
    Use a capacity of 5

*/
#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
#include "empty_buffer.h"
#include "dog.h"

using namespace std;

int main() {
    cout << "\n*************** <int> Circular Buffer Demo ******************\n";
    //  FINISH THIS SECTION
    CircularBuffer<int, 6> intbuff;

    cout << intbuff;


    cout << "\n*************** <string> Circular Buffer Demo ******************\n";

    //  FINISH THIS SECTION --
    // create a vector of words
    // use back_insert_iterator to fill the buffer

    CircularBuffer<string, 5> stringbuff;


    cout << "\n*************** <Dog> Circular Buffer Demo ******************\n";

    //  FINISH THIS SECTION
    
    CircularBuffer<dog, 5> dogbuff;


    cout << endl;

}
