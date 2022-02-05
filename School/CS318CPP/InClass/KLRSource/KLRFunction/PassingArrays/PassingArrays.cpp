// PassingArrays

#include <iostream>
#include <iterator> // std::size
using namespace std;

int findMaxElement(int* arr, int length);
void printArray(const string* arr, int length);
void printArray(const int* arr, int length);
void addOneToElement(int* arr, int length);

int main()
{
    int ages[]{ 22, 45, 2, 67, 18, 70 };
    int numPeople{ static_cast<int>(std::size(ages)) };

    int maxAge = findMaxElement(ages, sizeof(ages) / sizeof(ages[0]));
   
    cout << "The oldest person is " << maxAge << '\n';

    // Using for each loop to find min and print values
    int minAge{ ages[0] };

    cout << "\nThe ages are: ";
    printArray(ages, sizeof(ages) / sizeof(ages[0]));


    addOneToElement(ages, sizeof(ages) / sizeof(ages[0]));
    cout << "\nThe updated ages are: ";
    printArray(ages, sizeof(ages) / sizeof(ages[0]));

    string names[]{ "Scarecrow", "Dorothy", "Cowardly Lion", "Wicked Witch", "Glinda"};
    cout << "\nCharacters: \n";
    printArray(names, sizeof(names) / sizeof(names[0]));
    cout << sizeof(names[1]) << " " << sizeof(names);

    cout << "\n";
    return 0;
}

int findMaxElement(int* arr, int length) {
    int maxElem = 0;

    for (int i=0; i < length; i++)     {
        if (arr[i] > maxElem) {
            maxElem = arr[i]; //access to array element through variable age
        }
    }

    return maxElem;

}

void addOneToElement(int* arr, int length) {
    for (int i = 0; i < length; i++) {
        arr[i]++;
     }
}

void printArray(const string* arr, int length) {
    for (int i = 0; i < length; i++) {
        cout << '\t' << arr[i] << '\n';
    }
}

void printArray(const int* arr, int length)
{
    for (int i = 0; i < length; i++) {
        cout << '\t' << arr[i] << '\n';
    }
}

