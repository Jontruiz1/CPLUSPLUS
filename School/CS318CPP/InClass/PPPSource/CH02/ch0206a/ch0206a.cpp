// ch0206a

// instead of std_facilities.h  include next two lines
#include <iostream> 
using namespace std;

int main() // C++ programs start by executing the function main
{
    cout << "Hello, World!\n"; // output "Hello, World!"

    //keep_window_open();        // wait for a character to be entered
    cin.get(); // instead of keep_window_open()
    return 0;
}