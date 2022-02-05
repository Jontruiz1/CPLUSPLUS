//ch0404-2-2:  example code from Chapter 4.4.2.3 "For-statements" 
#include "..\libroot\std_lib_facilities.h" //location of header in CH04 Solution

//------------------------------------------------------------------------------

int square(int x)    // return the square of x
{
    return x*x;
}

//------------------------------------------------------------------------------

// calculate and print a table of squares 0-99
int main()
{
    for (int i = 0; i<100; ++i) {    // for i in the [0:100) range
        cout << i << '\t' << square(i) << '\n';
        //++i; // what's going on here? It smells like an error!
    }
}

//------------------------------------------------------------------------------
