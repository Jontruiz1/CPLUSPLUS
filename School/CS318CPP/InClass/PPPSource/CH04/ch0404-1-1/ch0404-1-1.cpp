// ch0404-1-1:  example code from Chapter 4.4.1.1 "If-statements" o

#include "..\libroot\std_lib_facilities.h" //location of header in CH04 Solution

//------------------------------------------------------------------------------

int main()
{
    int a = 0;
    int b = 0;
    cout << "Please enter two integers\n";
    cin >> a >> b;

    if (a<b)    // condition
        // 1st alternative (taken if condition is true):
        cout << "max(" << a << "," << b <<") is " << b <<"\n";
    else
        // 2nd alternative (taken if condition is false):
        cout << "max(" << a << "," << b <<") is " << a << "\n";
}

//------------------------------------------------------------------------------

