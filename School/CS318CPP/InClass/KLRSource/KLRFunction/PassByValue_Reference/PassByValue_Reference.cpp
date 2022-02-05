// PassByValue_Reference
#include <iostream>
using namespace std;

int add(int x, int y);
void addTwo(int& num);
void displayMessage(const string& msg);

int main()
{
    int n{ 5 };
    int m{ 20 };
    cout << "The sum n and m is: " << add(n, m) << '\n';

    cout << "\nValue of m is: " << m << '\n';
    addTwo(m);
    cout << "Value of m after call to addTwo is: " << m << '\n';

    string message = "Follow the yellow brick road!";
    displayMessage(message);

    return 0;
}

// uses pass by value -- arguments' values copied into formal parameters
int add(int x, int y) // definition of add
{
    return x + y;
}

// uses pass by reference -- formal parameter is an alias for the call's argument
//                              modification of the formal parameter changes the argument
void addTwo(int& num) //num is an alias for the arguments in the call
{
    num = num + 2;
}

// uses pass by const reference -- alias for argument, but cannot modify
void displayMessage(const string& msg) // msg is a const reference
{
    cout << "\nMessage is: " << msg << '\n';
    //msg = "hello";  // compile error cannot change a const reference
}