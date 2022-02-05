// StaticCast
// Explicitly cast from one type to another
#include <iostream>
using namespace std;

int main()
{
    char c{ 'f' };
    int num1 = static_cast<int>(c);

    cout << "c is " << c << '\n';
    cout << "num1 is " << num1 << '\n';

    int x{ 5 }, y{ 10 };

    cout << "x divided by y is " << x/y << '\n'; // int division
    cout << "x divided by y is " << static_cast<float>(x / y) << '\n'; // still int but cast result
    cout << "x divided by y is " << static_cast<float>(x) / y << '\n'; // cast a operand to float
    

    return 0;
}