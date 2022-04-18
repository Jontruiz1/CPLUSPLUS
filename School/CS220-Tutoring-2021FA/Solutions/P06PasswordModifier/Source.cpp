// P06PasswordModifier
#include <iostream>
#include <string>
using namespace std;

int main() {
    string inputPassword;
    string endChar = "!";
    int i = 0; // index to letter position

    cout << "** Password Modifier *** "<< endl;

    cout << "\nEnter a password without spaces: ";
    cin >> inputPassword;

    while (inputPassword != "quit") {
        

        while (i < inputPassword.size()) {
            if (inputPassword.at(i) == 'i') {
                inputPassword.at(i) = '1';
            }
            else if (inputPassword.at(i) == 'a') {
                inputPassword.at(i) = '@';
            }
            else if (inputPassword.at(i) == 'm') {
                inputPassword.at(i) = 'M';
            }
            else if (inputPassword.at(i) == 'B') {
                inputPassword.at(i) = '8';
            }
            else if (inputPassword.at(i) == 's') {
                inputPassword.at(i) = '$';
            }

            ++i;
        }

        inputPassword += endChar;
        cout << "\nModified password is: " << inputPassword << endl;

        cout << "\nEnter a password without spaces: ";
        cin >> inputPassword;
        i = 0;
    }

    return 0;
}