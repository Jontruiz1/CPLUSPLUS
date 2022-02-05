//  ch0303-second

#include "..\libroot\std_lib_facilities.h" 

// read name and age (2nd version)
int main()
{
    cout << "please enter your first_name and age: ";
    string first_name = "???"; // string variable
                               // ("???" means "don't know the name")
    int age = -1;              // integer variable (-1 means "don't know the age")
    cin >> first_name >> age;  // read a string followed by an integer
    cout << "Hello, " << first_name << " (age " << age << ")\n";

    keep_window_open();
}
