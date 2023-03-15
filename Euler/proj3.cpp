#include <iostream>

using namespace std;


bool is_prime(unsigned long long a){
    for(unsigned long long i = 2; i < a; ++i){
        if(a % i == 0){
            return false;
        }
    }
    return true;
}

unsigned long long largestPrimeFactor(unsigned long long a){
    unsigned long long num = a;
    unsigned long long max = 0;
    unsigned long long i = 2;
    while(num > 4){
        if(is_prime(i)) max = i;
        if(num % i == 0) {
            num /= i;
            i = 2;
        }
        ++i;
    }
    return max;
}


int main(){
    cout << largestPrimeFactor(600851475143);
}
