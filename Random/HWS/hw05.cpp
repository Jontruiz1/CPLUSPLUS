
#include <iostream>
#include <fstream>

using namespace std;

int main(){
    ofstream file;
    string line;
    long i = 0;

    file.open("File1.txt");

    for(int i = 0; i < 10; ++i){
        file << i << endl;
    }
    file.close();

    file.open("File2.txt");
    for(int i = 0; i < 5000; ++i){
        file << i << endl;
    }
    file.close();
    
}