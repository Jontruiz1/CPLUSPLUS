#include <iostream>
#include <vector>

using namespace std;

int romToNum(string rom) {
    int result = 0;
    for (size_t i = 0; i < rom.size(); ++i) {
        switch (rom[i]) {
        case 'I':
            if (rom[i + 1] == 'V') {
                result += 4;
            }
            else if (rom[i + 1] == 'X') {
                result += 9;
            }
            else {
                result += 1;
            }
            break;
        case 'V':
            result += 5;
            break;
        case 'X':
            result += 10;
            break;
        case 'L':
            result += 30;
            break;
        }
    }
    return result;

}


vector<string> sortRoman(vector<string> names) {
    for (size_t i = 0; i < names.size(); ++i) {
        string s = names[i];

    }
}

int main() {
    vector<string> names = {"Steven XL", "Steven XVI"}
}