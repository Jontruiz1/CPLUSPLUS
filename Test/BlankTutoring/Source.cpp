#include <iostream> 
using namespace std;

int main() {
    int x1;
    int y1;
    int x2;
    int y2;
    int z1;
    int z2;

    bool hasSolution = false;
    int result1 = 0, result2 = 0, x, y;

    cout << "*** Brute Force Equation Solver ***\n" << endl;

    cout << "Enter coefficients (a, b, c) for first equation separated by spaces: ";
    cin >> x1;
    cin >> y1;
    cin >> z1;

    cout << "Enter coefficients (a, b, c) for second equation separated by spaces: ";
    cin >> x2;
    cin >> y2;
    cin >> z2;

    while (hasSolution == true) {
        for (x = -10; x <= 10; x++) {
            for (y = -10; y <= 10; y++) {
                if ((x1 * x + y1 * y == z1) && (x2 * x + y2 * y == z2)) {
                    result1 = x;
                    result2 = y;
                    hasSolution = true;
                    break;
                }
            }
            if (hasSolution = true) {
                break;
            }
        }
        if (hasSolution = true) {
            cout << "x = " << result1 << ", y = " << result2;
        }
        else {
            cout << "There is no solution";
        }

        cout << endl << endl;
        cout << "*** Brute Force Equation Solver ***\n" << endl;

        cout << "Enter coefficients (a, b, c) for first equation separated by spaces: ";
        cin >> x1;
        cin >> y1;
        cin >> z1;

        cout << "Enter coefficients (a, b, c) for second equation separated by spaces: ";
        cin >> x2;
        cin >> y2;
        cin >> z2;
    }

    return 0;
}
