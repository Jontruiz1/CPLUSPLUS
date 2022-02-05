// ch0405-2: example code from Chapter 4.5.2 "Function declarations" 

#include "..\libroot\std_lib_facilities.h" //location of header in CH04 Solution

//------------------------------------------------------------------------------

int    square(int);    // declaration of square
double sqrt(double);   // declaration of sqrt

int main()
{
    int x = square(44);
}

//------------------------------------------------------------------------------

int square(int x)      // definition of square
{
    return x*x;
}

//------------------------------------------------------------------------------
