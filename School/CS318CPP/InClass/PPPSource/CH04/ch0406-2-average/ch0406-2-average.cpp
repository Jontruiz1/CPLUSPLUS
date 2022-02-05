// ch0406-2-average: example code from Chapter 4.6.2 "A numeric example" 

#include "..\libroot\std_lib_facilities.h" //location of header in CH04 Solution

//------------------------------------------------------------------------------

// compute mean and median temperatures
int main()
{
    vector<double> temps;        // temperatures
    double temp;
    cout << "\nEnter a series of temperatures (end with any character): ";
    while (cin>>temp)            // read 
        temps.push_back(temp);   // put into vector

    // compute mean temperature:
    double sum = 0;
    for (int i = 0; i< temps.size(); ++i) sum += temps[i];
    cout << "Average temperature: " << sum/temps.size() << endl;

    // compute median temperature:
    sort(temps.begin(),temps.end()); // sort temps
    // "from the beginning to the end."
    cout << "Median temperature: " << temps[temps.size()/2] << endl;
}

//------------------------------------------------------------------------------
