// ch0405-1:  example code from Chapter 4.5.1 "Why bother with functions?" 
#include "..\libroot\std_lib_facilities.h" //location of header in CH04 Solution

//------------------------------------------------------------------------------

void print_square(int v)
{
    cout << v << '\t' << v*v << '\n';
}

//------------------------------------------------------------------------------

int main()
{
    for (int i = 0; i<100; ++i) print_square(i);
}

//------------------------------------------------------------------------------
