// ch0403-3:  example code from Chapter 4.3.3 "Conversions" 

#include "..\libroot\std_lib_facilities.h" //location of header in CH04 Solution

//------------------------------------------------------------------------------

int main()
{
    double d = 2.5;
    int i = 2;

    double d2 = d/i; // d2 == 1.25
    int i2 = d/i;    // i2 == 1

    d2 = d/i;        // d2 == 1.25
    i2 = d/i;        // i2 == 1

    {
        double dc;
        cin >> dc;
        double df = 9/5*dc+32;    // beware -- integer division!
    }

    {
        double dc;
        cin >> dc;
        double df = 9.0/5*dc+32;  // better
    }
}

//------------------------------------------------------------------------------
