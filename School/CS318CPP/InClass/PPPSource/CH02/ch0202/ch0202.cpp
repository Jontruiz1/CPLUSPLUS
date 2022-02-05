// ch0202:  program outputs the message "Hello, World!" to the monitor

//#include "..\libroot\std_lib_facilities.h" //location of header in CH02 Solution
#include <iostream>
using namespace std;

// C++ programs start by executing the function main
int main() 
{
    // output "Hello, World!" followed by a new line \n
    cout << "Hello, World!\n"; 
   
    cin.get(); //keep window open
    return 0; //return a value indicating success
}

