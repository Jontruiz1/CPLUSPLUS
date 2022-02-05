//  ch0303-third

#include "..\libroot\std_lib_facilities.h" 

int main()
{
    cout << "please enter your first and second names\n";
    string first;
    string second;
    cin >> first >> second;    // read two strings
    cout << "Hello, " << first << ' ' << second << '\n';

    keep_window_open();
}

