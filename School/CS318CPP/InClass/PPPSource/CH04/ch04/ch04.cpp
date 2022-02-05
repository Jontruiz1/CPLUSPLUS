// ch04
// 

#include "..\libroot\std_lib_facilities.h" //location of header in CH04 Solution

//------------------------------------------------------------------------------

int square(int x) // return the square of x
{
    return x*x;
}

//------------------------------------------------------------------------------

// calculate and print a table of squares 0-99
int main()
{
    int i = 0;    // start from 0
    while (i<100) {
        cout << i << '\t' << square(i) << '\n';
        ++i ;     // increment i (that is, i becomes i+1)
    }
}

//------------------------------------------------------------------------------
