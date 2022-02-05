// ch0404-2-2:  example code from Chapter 4.4.2.2 "Blocks"
#include "..\libroot\std_lib_facilities.h" //location of header in CH04 Solution

//------------------------------------------------------------------------------

int main()
{
    int a = 7;
    int b = 4;

    if (a<=b) { // do nothing
    }
    else {      // swap a and b
        int t = a;
        a = b;
        b = t;
    }
}

//------------------------------------------------------------------------------
