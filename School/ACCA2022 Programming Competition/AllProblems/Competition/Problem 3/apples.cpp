#include <iostream>

using namespace std;

bool isfair(int a, int b) {
    for (int i = 2; i <= b; i++) {
        if (a % i == 0) {
            return true;
        }

    }
    return false;
}

int main() {
    // a cannot be less than b
    // a is not equal to b

    int a;
    int b;

    cin >> a;
    cin >> b;
    if (isfair(a, b)) {
        cout << "Yes";
    }
    else {
        cout << "No";
    }

    return 0;
}