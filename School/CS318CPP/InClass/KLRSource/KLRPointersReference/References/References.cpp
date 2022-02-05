// References

/*
*	Three types:
*		References to non-const values
*		References to const values (often called “const references”)
*		r-value references (later on this)
*
*	Treated as alias for another variable name
*/

#include <iostream>
using namespace std;

int main()
{
    int value{ 20 }; // normal integer
    int& ref{ value }; // reference to variable value

    cout << "Variable value: " << value << '\n';

    value = 13;
    cout << "Variable value: " << value << '\n';

    ref = 25;
    cout << "Variable value: " << value << '\n';

    ++ref;
    cout << "Variable value after ref incremented: " << value << '\n';

    return 0;

}