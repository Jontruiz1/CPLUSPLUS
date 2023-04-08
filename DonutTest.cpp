#include <iostream>
#include <cmath>

using namespace std;

int main(){
    double A = 0, B = 0;
    double z[1760];
    char b[1760];
    const string chars = ".,-~:;=!*#$@";

    printf("\x1b[2J", stdout);
    
    while(true){
        fill(z, z+(end(z) - begin(z)), 0);
        fill(b, b+(end(b) - begin(b)), 32);
        for(int i = 0; i < 628; i+=7){
            for(int j = 0; j < 628; j += 2){
                double c = sin(j), d = cos(i), e = sin(A), f = sin(i), g = cos(A);
                double h = d + 2;
                double D = 1 / (c * h * e + f * g + 5);
                double l = cos(j), m = cos(B), n = sin(B);
                double t = c * h * g - f * e;
                int x = (40 + 40 * D * (l * h * m - t * n));
                int y = (12 + 20 * D * (l * h * n + t * m));
                int o = (x + 80 * y);
                int N = (8 * ((f * e - c * d * g) * m - c * d * e - f * g - l * d * n));
                if(22 > y && y > 0 && x > 0 && 80 > x && D > z[o]){
                    z[o] = D;
                    b[o] = chars[N > 0 ? N : 0];
                }
            }
        }
        printf("\x1b[H", stdout);
        for(int k = 0; k < 1761; ++k, B += 0.00010, A += 0.00010) cout << (k % 80 ? b[k] : '\n');
    }
}