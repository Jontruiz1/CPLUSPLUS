// ch0304-concatenate

#include "..\libroot\std_lib_facilities.h" 

// read first and second name:
int main()
{
    cout << "please enter your first and second names\n";
    string first;
    string second;
    cin >> first >> second;                // read two strings
    string name = first + ' ' + second;    // concatenate strings
    cout << "Hello, " << name << '\n';
}