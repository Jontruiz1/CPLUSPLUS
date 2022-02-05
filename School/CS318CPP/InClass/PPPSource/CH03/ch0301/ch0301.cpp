// ch0301:  read and write first name

#include <iostream>
#include <string>
using namespace std;

int main()
{
    cout << "Please enter your first name (followed by 'enter'):\n";
    string first_name;    // first_name is a variable of type string
    cin >> first_name;    // read characters into first_name up to a white space
    // combination of literals and variables
    cout << "Hello, " << first_name << "!\n"; 
    cout << "first_name" << " is " << first_name;
    //return 0;   optional but might need it to keep compiler happy

    cin.get();
}

