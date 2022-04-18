//P03TextMessageDecoder
#include <iostream>
#include <string>
using namespace std;

int main() {
    string userLine;

    cout << " *** P03: Text Message Decoder ***\n" << endl;

    cout << " Enter text message: ";
    getline(cin, userLine);

    // Note that a series of if's are used, NOT if-else (common error)

    cout << endl;

    if (userLine.find("BFF") != string::npos) {
        cout << " BFF: best friend forever" << endl;
    }

    if (userLine.find("IDK") != string::npos) {
        cout << " IDK: I don't know" << endl;
    }

    if (userLine.find("JK") != string::npos) {
        cout << " JK: just kidding" << endl;
    }

    if (userLine.find("TMI") != string::npos) {
        cout << " TMI: too much information" << endl;
    }

    if (userLine.find("TTYL") != string::npos) {
        cout << " TTYL: talk to you later" << endl;
    }


    return 0;
}