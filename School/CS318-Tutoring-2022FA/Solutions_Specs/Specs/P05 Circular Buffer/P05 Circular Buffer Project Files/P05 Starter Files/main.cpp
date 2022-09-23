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
#include "circular_buffer.h"
#include "dog.h"

using namespace std;

int main() {
    cout << "\n*************** <int> Circular Buffer Demo ******************\n";
	//  FINISH THIS SECTION
    CircularBuffer<int, 5> intbuff;
    cout << "Initial State" << endl;
    cout << intbuff;

    
    for (int i = 0; i <= 70; i += 10) {
        cout << "Pushing " << i << endl;
        intbuff.push_back(i);
        cout << intbuff;
    }

    while (!intbuff.empty()) {
        cout << "Popping: " << intbuff.head() << endl;
        intbuff.pop();
        cout << intbuff;
    }

    
    
    cout << "\n*************** <string> Circular Buffer Demo ******************\n";

    //  FINISH THIS SECTION --
    // create a vector of words
    // use back_insert_iterator to fill the buffer

    vector<string> words = {"dorothy", "wizard", "the", "wonderful", "world", "of", "oz"};
    CircularBuffer<string, 5> stringbuff;

    cout << "Initial state" << endl;
    cout << stringbuff;

    back_insert_iterator<CircularBuffer<string, 5>> backit(stringbuff);
    copy(words.begin(), words.end(), backit);

    cout << "After using back_insert_iterator" << endl;
    cout << stringbuff;

    while (!stringbuff.empty()) {
        cout << "Popping: " << stringbuff.head() << endl;
        stringbuff.pop();
        cout << stringbuff;
    }

    cout << "\n*************** <Dog> Circular Buffer Demo ******************\n";

	//  FINISH THIS SECTION
    CircularBuffer<dog, 5> dogbuff;
   

    dogbuff.push_back(dog("Guinness", "Wheaten", 9));
    dogbuff.push_back(dog("Grimlock", "Lab", 2));
    dogbuff.push_back(dog("Optimus", "Bulldog", 5));
    dogbuff.push_back(dog("Murphy", "Lab", 14));
    dogbuff.push_back(dog("Floyd", "Beagle", 12));
    cout << dogbuff;

    cout << "dogs Full?: " << (dogbuff.full() == 1 ? "true" : "false") << endl << endl;

    dogbuff.push_back(dog("Snoopy", "Beagle", 100));
    cout << dogbuff;

    dogbuff.push_back(dog("Archie", "Brittany", 1));
    cout << dogbuff;
    
    dogbuff.push_back(dog("Penny", "Beagle", 2));
    cout << dogbuff;

    while (dogbuff.size() > 0) {
        cout << "Popping: " << endl <<dogbuff.head()<< endl;
        dogbuff.pop();
        cout  << dogbuff;
    }
    
    dogbuff.full();


    cout << endl;
    
}
