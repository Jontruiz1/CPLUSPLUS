
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
    CircularBuffer<int, 5> intBuffer;
    cout << "\nInitial state\n";
    cout << intBuffer;

    for (int i = 0; i <= 70; i += 10) {
        cout << "Pushing " << i << endl;
        intBuffer.push_back(i);
        cout << intBuffer;
    }

    while (!intBuffer.empty()) {
        cout << "Popping: " << intBuffer.head() << endl;
        intBuffer.pop();
        cout << intBuffer;
    }
    cout << "\n*************** <string> Circular Buffer Demo ******************\n";

    //  FINISH THIS SECTION --
    // create a vector of words
    CircularBuffer<string, 5> stringBuffer;
    vector<string> words = { "dorothy", "wizard", "the", "wonderful", "world", "of", "oz" };

    // use back_insert_iterator to fill the buffer
    back_insert_iterator<CircularBuffer<string, 5>> back_it(stringBuffer);

    cout << "\nInitial state\n";
    cout << stringBuffer;

    copy(words.begin(), words.end(), back_it);

    cout << "After using back_insert_iterator" << endl;
    cout << stringBuffer;

  
    while (!stringBuffer.empty()) {
        cout << "Popping: " << stringBuffer.head() << endl;
        stringBuffer.pop();
        cout << stringBuffer;
    }


    cout << "\n*************** <Dog> Circular Buffer Demo ******************\n\n";

    //  FINISH THIS SECTION
    CircularBuffer<dog, 5> dogBuffer;

    dogBuffer.push_back(dog("Guinness", "Wheaten", 9));
    dogBuffer.push_back(dog("Grimlock", "Lab", 2));
    dogBuffer.push_back(dog("Optimus", "Bulldog", 5));
    dogBuffer.push_back(dog("Murphy", "Lab", 14));
    dogBuffer.push_back(dog("Floyd", "Beagle", 12));
    cout << dogBuffer;

    if (dogBuffer.full()) {
        cout << "dogs Full?: true" << endl << endl;
    }
    else {
        cout << "dogs Full?: false" << endl << endl;
    }

    dogBuffer.push_back(dog("Snoopy", "Beagle", 100));
    cout << dogBuffer;

    dogBuffer.push_back(dog("Archie", "Brittany", 1));
    cout << dogBuffer;

    dogBuffer.push_back(dog("Penny", "Beagle", 2));
    cout << dogBuffer;

    while (!dogBuffer.empty()) {
        cout << "Popping: " << dogBuffer.head() << endl;
        dogBuffer.pop();
        cout << endl;
        cout << dogBuffer;
    }
}

