#include <iostream>
#include <list>
#include <fstream>
#include <regex>

using namespace std;

int main(){
    ofstream file;
    ifstream parser;
    string curr;
    std::list<int> sixes;
    file.open("sixes.txt");

    for(unsigned int i = 0; i < 10000; ++i){
        if(i % 6 == 0 && i % 3 == 0 && i % 2 == 0){
            file << i << endl;
        }
    }
    file.close();
    
    parser.open("sixes.txt");
    while(parser >> curr){
        if (regex_match(curr, regex("[1-3]+"))){
            cout << curr << endl;
        }
    }
    parser.close();


}