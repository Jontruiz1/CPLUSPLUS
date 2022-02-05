/*  REQUIREMENTS NOTES:

    SEE ADDITIONAL REQUIREMENT AT LINE 48
    DO NOT CHANGE ANYTHING ABOVE THIS LINE OTHER THAN IMPORTING THE DOG CLASS

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
    CircularBuffer<int, 5> buffer;
    cout << "\nInitial state\n";
    cout << buffer;

    for (int i = 0; i < 8; i++) {
        cout << "\nPushing " << i * 10 << "\n";
        buffer.push_back(i * 10);
        cout << buffer;
    }

    while (!buffer.empty()) {
        cout << "\nPopping: " << buffer.head() << "\n";
        buffer.pop();
        cout << buffer;
    }

    cout << "\n*************** <string> Circular Buffer Demo ******************\n";
    vector<string> words{ "welcome", "to", "the", "wonderful", "world", "of", "oz" };

    CircularBuffer<string, 5> strings;
    cout << "\nInitial state\n";
    cout << strings;

    copy(begin(words), end(words), back_insert_iterator<CircularBuffer<string, 5>>(strings));
    cout << "\nAfter using back_insert_iterator" << endl;
    cout << strings;

    while (!strings.empty()) {
        cout << "\nPopping: " << strings.head() << "\n";
        strings.pop();
        cout << strings;
    }

    cout << "\n*************** <Dog> Circular Buffer Demo ******************\n";

    // COMPLETE A SECTION TO TEST THIS IMPLEMENTATION WITH THE DOG CLASS WE HAVE USED
    //	IN CLASS EXAMPLES

    // CAPACITY SHOULD BE AT LEAST 5

        // empty set container 
    CircularBuffer<dog, 5> dogs;

    dogs.push_back(dog("Guinness", "Wheaten", 9));
    dogs.push_back(dog("Grimlock", "Lab", 2));
    dogs.push_back(dog("Optimus", "Bulldog", 5));
    dogs.push_back(dog("Murphy", "Lab", 14));
    dogs.push_back(dog("Floyd", "Beagle", 12));
    cout << "\n" << dogs;

    cout << "\ndogs Full?: " << boolalpha << dogs.full() << "\n";

    dogs.push_back(dog("Snoopy", "Beagle", 100));
    cout << "\n" << dogs;
    dogs.push_back(dog("Archie", "Brittany", 1));
    cout << "\n" << dogs;
    dogs.push_back(dog("Penny", "Beagle", 2));
    cout << "\n" << dogs;
    
    while (!dogs.empty()) {
        cout << "\nPopping: " << dogs.head() << "\n";
        dogs.pop();
        cout << "\n" << dogs;
    }

    cout << endl;
}
