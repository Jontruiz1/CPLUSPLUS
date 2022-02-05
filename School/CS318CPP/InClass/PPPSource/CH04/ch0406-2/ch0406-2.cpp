// ch0406-2: example code from Chapter 4.6.2 "A numeric example" 

#include "..\libroot\std_lib_facilities.h" //location of header in CH04 Solution

//------------------------------------------------------------------------------

// read some temperatures into a vector
int main()
{
    vector<double> temps;         // temperatures
    double temp;
    while (cin>>temp)             // read 
        temps.push_back(temp);    // put into vector
    // ... do something ...
}

//------------------------------------------------------------------------------
