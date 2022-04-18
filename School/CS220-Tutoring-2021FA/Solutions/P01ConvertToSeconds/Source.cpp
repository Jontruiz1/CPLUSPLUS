//P01ConvertToSeconds
#include <iostream>
using namespace std;

int main() {
    int seconds;
    int minutes;
    int hours;
        
    cout << "*** P01: Convert To Seconds ***\n" << endl;

    // get the number of hours, minutes, and seconds from the user
    cout << "Enter hours: ";
    cin >> hours;
    cout << "Enter minutes: ";
    cin >> minutes;
    cout << "Enter seconds: ";
    cin >> seconds;

    // calculate number of seconds from hours (3600 seconds in an hour)
    seconds += hours * 3600;

    // calculate number of seconds from minutes (60 seconds in a minute)
    seconds += minutes * 60;

    // print the results
    cout << endl;
    cout << "Total Seconds: " << seconds << endl;

    return 0;
}
