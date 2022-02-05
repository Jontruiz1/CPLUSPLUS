// ch0309-1

#include "..\libroot\std_lib_facilities.h" 

int main()
{
    char c = 'x';
    int i1 = c;
    int i2 = 'x';
    char c2 = i1;

    cout << c << ' ' << i1 << ' ' << c2 << '\n'; // This will print: x 120 x

    double d1 = 2.3;
    double d2 = d1 + 2; // 2 is converted to 2.0 before adding
    d1 = d1 - 3;

    cout << "d1 = " << d1 << endl;

    if (d1 < 0)        // 0 is converted to 0.0 before comparison
        cout << "d1 is negative" << endl;

    cin.get();

    return 0;
}

