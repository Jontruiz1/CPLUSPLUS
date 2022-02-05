//ArraysPointers
#include <iostream>
using namespace std;

int main()
{
    //Note the values printed are the same -- name of array becomes a pointer automatically

    int arr1[]{ 27, 35, 40 };

    // print address of the array's first element
    cout << "Element 0 has address: " << &arr1[0] << '\n';

    // print the value of the pointer the array decays to
    cout << "Array name is a pointer with address: " << arr1 << '\n';
 
    //***********************************************************************************

    cout << "\nFirst element of arr1 " << *arr1 << '\n'; 
    char name[]= "Tinman"; // C-style string array of characters
    cout << "\nname is " << name << endl;
    cout << "First element of name " << *name << '\n'; 

    //***********************************************************************************
    
    char* ptr{ name }; // assign a pointer to point to name
    cout << *ptr << '\n'; // will print T
    
    //***********************************************************************************

    int* ptr2(arr1);
    cout << sizeof(arr1) << '\n'; // sizeof(int) * array length in bytes
    cout << sizeof(ptr2) << '\n'; // size of pointer in bytes

    return 0;

}