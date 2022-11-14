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
#include "Circular_Buffer.h"
#include "dog.h"

using namespace std;

int main() {
    cout << "\n*************** <int> Circular Buffer Demo ******************\n";
    //  FINISH THIS SECTION
    cout << "Initial State" << endl;
    CircularBuffer<int, 5> intBuf;
    cout << intBuf;
   
    for (int i = 0; i <= 70; i += 10) {
        cout << "Pushing " << i << endl;
        intBuf.push_back(i);
        cout << intBuf << endl;
    }

    while (!intBuf.empty()) {
        intBuf.pop();
        cout << endl << intBuf << endl;
    }

    cout << "\n*************** <string> Circular Buffer Demo ******************\n";
    //  FINISH THIS SECTION 
    // create a vector of words
    // use back_insert_iterator to fill the buffer

    CircularBuffer<string, 5> stringBuf;
    vector<string> words = { "filler", "word", "the", "wonderful", "world", "of", "oz" };
    
    cout << "Initial state\n";
    cout << stringBuf << endl;


    cout << "After using back_insert_iterator\n";
    copy(words.begin(), words.end(), back_inserter(stringBuf));
    cout << stringBuf << endl;

   while(!stringBuf.empty()) {
        stringBuf.pop();
        cout << endl << stringBuf << endl;
    }

    cout << "\n*************** <Dog> Circular Buffer Demo ******************\n";
    CircularBuffer<dog, 5> dogBuf;
    vector<dog> dogs = {
        dog("Guiness", "Wheaten", 9),
        dog("Grimlock", "Lab", 2),
        dog("Optimus", "Bulldog", 5),
        dog("Murphy", "Lab", 14),
        dog("Floyd", "Beagle", 12), };
    copy(dogs.begin(), dogs.end(), back_inserter(dogBuf));
    cout << dogBuf << endl;
    cout << boolalpha << "dogs Full?: " << dogBuf.full() << endl << endl;
    dogBuf.push_back(dog("Snoopy", "Beagle", 100));
    cout << dogBuf << endl;

    dogBuf.push_back(dog("Archie", "Brittany", 1));
    cout << dogBuf << endl;

    dogBuf.push_back(dog("Penny", "Beagle", 2));
    //  FINISH THIS SECTION

    cout << dogBuf;

    while (!dogBuf.empty()) {
        cout << endl;
        dogBuf.pop();
        cout << endl << endl << dogBuf;
    }

    cout << endl;
}
