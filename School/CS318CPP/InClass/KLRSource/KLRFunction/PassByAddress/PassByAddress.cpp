// PassByAddress
#include <iostream>
using namespace std;

void addTwo(int* num);
void updateMessage(string* msg);
void displayMessage(const string* msg);

int main()
{
    int n{ 5 };
    int m{ 20 };

    cout << "\nValue of n is: " << n << '\n';
    addTwo(&n);
    cout << "Value of n after call to addTwo is: " << n << '\n';

    string message = "Follow the yellow brick road!";
    cout << "\nMessage: " << message << '\n';
    cout << "Address of actual parameter message: " << &message << endl;
    updateMessage(&message);
    cout << "Updated Message: " << message << '\n';

    displayMessage(& message);

    return 0;
}


// uses pass by address 
void addTwo(int* num) //num is an alias for the arguments in the call
{
    num = num + 2;
}

// uses pass by address
void updateMessage(string* msg) // msg is a const reference
{
    *msg = "There's no place like home"; 
    cout << "\nAddress of formal parameter msg: " << msg << endl;

}

// uses pass by const address -- cannot change formal argument value
void displayMessage(const string* msg) // msg is a const reference
{
    //*msg = "There's no place like home";
    cout << "\ndisplayMessage: Address of formal parameter msg: " << msg << endl;

}