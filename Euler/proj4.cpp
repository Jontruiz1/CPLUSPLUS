#include <iostream>
using namespace std;

bool isPrime(unsigned long curr){
    // if a number ends in 0, 2, 4, 6, and 8 it is not prime
    if(curr % 2 == 0) return false;
    if((curr + 1) % 6 == 0 || ((curr-1) % 6 == 0)) return true;

    for(unsigned long i = curr-1; i >= 2; --i){
        if(curr % i == 0) return false;
    } 
    return true;

}


int problem(){
    int i, j;

    for(int i = 999; i >=101; --i){
        for(int j = 999; j >= 101; --j){
            if(isPrime(i * j)) return i*j;
            cout << i << " " << j;
        }
    }
    return -1;
}



int main(){

    cout << isPrime(994009);
}