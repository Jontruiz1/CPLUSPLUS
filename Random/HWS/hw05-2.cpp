#include <iostream>

using namespace std;

int main(){
    for(long long i = 1; i < 50000; ++i){
        for(long long j = 1; j < 5000; ++j){
            cout << i * j << endl;
        }
    }
}