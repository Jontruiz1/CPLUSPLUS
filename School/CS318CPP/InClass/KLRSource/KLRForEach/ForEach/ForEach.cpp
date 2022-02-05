// ForEach

#include <iostream>
#include <iterator> // std::size
using namespace std;

int main()
{
    constexpr int ages[]{ 22, 45, 2, 67, 18, 70 };
    constexpr int numPeople{ static_cast<int>(size(ages)) }; //looks like it works here --C++17?

    int maxAge{ 0 }; // keep track of our largest score

    // Using standard for loop
    for (int person{ 0 }; person < numPeople; ++person)
    {
        if (ages[person] > maxAge)
        {
            maxAge = ages[person];
        }
    }
    cout << "The oldest person is " << maxAge << '\n';

    // Using for each loop to find min and print values
    int minAge{ ages[0] };

    cout << "\nThe ages are: ";

    for (int age : ages)
    {
        if (age < minAge) {
            minAge = age; //access to array element through variable age
        }
        cout << age << ' ';
    }
    cout << "\n\nThe youngest person is " << minAge << '\n';

    // Using auto and reference 

    string names[]{ "Scarecrow", "Dorothy", "Cowardly Lion", "Wicked Witch", "Glinda" };

    cout << "\nCharacters: \n";
    //for (auto el : names) // el is a copy of the current array 
    for (auto& el : names)  // el is a ref to actual array element
    {
        cout << '\t' << el << '\n';
    }

    cout << "\n";
    return 0;
}