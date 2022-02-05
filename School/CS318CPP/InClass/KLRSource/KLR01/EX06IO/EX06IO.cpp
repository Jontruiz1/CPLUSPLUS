//EX06IO
/*
*/
#include <iostream>
#include <string>

// see what happens when the following is commented out
using namespace std;

int main()
{
    int a{ 5 };
    cout << "a is " << a << "\n";

    double y = 0;
    cout << "\nEnter amount: ";
    cin >> y;
    cout << "y is " << y << "\n";

    string firstName{};
    cout << "\nEnter your first Name: ";
    cin >> firstName;
    cout << "First Name entered is " << firstName << "\n";

    string lastName{};
    cout << "\nEnter your last Name: ";
    cin >> lastName;
    cout << "Last Name entered is " << lastName << "\n";

    cout << "\nEnter amount: ";
    cin >> y;
    cout << "y is now " << y << "\n";

    string fullName;
    cout << "\nEnter your full Name: ";
    getline(cin, fullName);
    cout << "Full Name entered is " << fullName << "\n";

    cin.get();
    return 0;
}