// ch0403

#include "..\libroot\std_lib_facilities.h" //location of header in CH04 Solution

//------------------------------------------------------------------------------

int main()
{
    // compute area: 
    int length = 20;         // a literal integer (used to initialize a variable)
    int width = 40;
    int area = length*width; // a multiplication

    length = 99;             // assign 99 to length

    //each perimeter is local to the code block {}

    {
        int perimeter = (length+width)*2; // add then multiply
        cout << "\nFirst block perimeter==" << perimeter << endl;
    }

    {
        int perimeter = length*2+width*2;
        cout << "\nSecond block perimeter==" << perimeter << endl;
    }

    {
        int perimeter = length+width*2;    // add width*2 to length
        cout << "\nThird block perimeter==" << perimeter << endl;
    }
}

//------------------------------------------------------------------------------
