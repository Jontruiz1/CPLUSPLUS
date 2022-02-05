// ch0405: example code from Chapter 4.5 "Functions" 

#include "..\libroot\std_lib_facilities.h" //location of header in CH04 Solution

//------------------------------------------------------------------------------

int square(int x)    // return the square of x
{
    return x*x;
}

//------------------------------------------------------------------------------

void write_sorry()    // take no argument; return no value
{
    cout << "Sorry\n";
}

//------------------------------------------------------------------------------

int main()
{
    cout << square(2) << '\n';  // print 4
    cout << square(10) << '\n'; // print 100

    square(2);                  // probably a mistake: unused return value
    //int v1 = square();        // error: argument missing
    //int v2 = square;          // error: parentheses missing
    //int v3 = square(1,2);     // error: too many arguments
    //int v4 = square("two");   // error: wrong type of argument - int expected

    write_sorry();
}

//------------------------------------------------------------------------------
