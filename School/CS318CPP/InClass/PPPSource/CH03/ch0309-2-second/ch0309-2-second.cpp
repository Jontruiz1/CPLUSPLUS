// ch0309-2-second

#include "..\libroot\std_lib_facilities.h" 

int main()
{
    double d =0;

    cout << "Enter a number: ";
    // repeat the statements below as long as we type in numbers
    while (cin>>d) {   
        int i = d;     // try to squeeze a double into an int
        char c = i;    // try to squeeze an int into a char
        int i2 = c;    // get the integer value of the character
        cout << "d==" << d              // the original double
             << " i=="<< i              // converted to int
             << " i2==" << i2           // int value of char
             << " char(" << c << ")\n"; // the char

        cout << "\nEnter a number: ";
    }

    double x = 2.7;
    int y = x;         // y becomes 2
    int a = 1000;
    char b = a;        // b becomes -24 (on some machines)

    cout << "\nx==" << x << "   y==" << y << "   a==" << a << "   b==" << b << endl;

    //return 0;
}
