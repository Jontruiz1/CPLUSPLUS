// ch0203: example code from Chapter 2.3 "Compilation" -- possible errors

#include "..\libroot\std_lib_facilities.h" //location of header in CH02 Solution

//integer main()                // error: unknown type integer
int main()
{
    //cout << "Hello, World!\n; // error: unterminated string constant
    //cout <  "Hello, World!\n";// error: no operator < defined
    //cout << 'Hello, World!\n';// error: invalid delimiter for strings
    //cout << "Hello, World!\n" // error: no semicolon
    cout << "Hello, World!\n";
    return 0;
}

