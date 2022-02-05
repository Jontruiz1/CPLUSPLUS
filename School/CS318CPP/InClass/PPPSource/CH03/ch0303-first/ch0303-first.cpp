// ch0303-first

#include "..\libroot\std_lib_facilities.h" 

// read name and age
int main()
{
    cout << "please enter your first name and age: ";
    string first_name;  // string variable
    int age;            // integer variable
    cin >> first_name;  // read a string
    cin >> age;         // read an integer
    cout << "Hello, " << first_name << " (age " << age << ")\n";

    keep_window_open();
}

