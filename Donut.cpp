#include <iostream>
#include <cmath>


int main(){
    double A = 0, B = 0;
    double z[1760];
    char b[1760];

    printf("\x1b[2J", stdout);
    while(true){
        std::fill(z, z+(std::end(z) - std::begin(z)), 0);
        std::fill(b, b+(std::end(b) - std::begin(b)), 32);

        for(int i = 0; i < 628; i+=7){
            for(int j = 0; j < 628; j += 2){
                double c = sin(j);
                double d = cos(i);
                double e = sin(A);
                double f = sin(i);
                double g = cos(A);
                double h = d + 2;
                double D = 1 / (c * h * e + f * g + 5);
                double l = cos(j);
                double m = cos(B);
                double n = sin(B);
                double t = c * h * g - f * e;
                int x = (int)(40 + 40 * D * (l * h * m - t * n));
                int y = (int)(12 + 20 * D * (l * h * n + t * m));
                int o = (int)(x + 80 * y);
                int N = (int)(8 * ((f * e - c * d * g) * m - c * d * e - f * g - l * d * n));
                if(22 > y && y > 0 && x > 0 && 80 > x && D > z[o]){
                    z[o] = D;
                    b[o] = ".,-~:;=!*#$@"[N > 0 ? N : 0];
                }
            }
        }
        printf("\x1b[H", stdout);
        for(int k = 0; k < 1761; ++k){
            std::cout << (k % 80 ? b[k] : '\n');
            A += 0.00006;
            B += 0.00006;
        }
    }
}