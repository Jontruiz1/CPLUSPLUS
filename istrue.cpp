#include <iostream>

using namespace std;

int isTrue(string boolean){
    if(boolean.compare("false") != 0 && boolean.compare("true") != 0){
        return 2;
    }

    int ans = 2;
    string truE = "true";
    string falsE = "false";
    for(int i =0 ; i < boolean.length(); ++i){
        if((falsE[i] != boolean[i])){
            boolean = truE;
            ans -= abs((int)truE.length() - (int)falsE.length());
            break;
        }
    }

    for(int i =0 ; i < boolean.length(); ++i){
        if(truE[i] != boolean[i]){
            ans -= abs((int)truE.length() - (int)falsE.length());
            boolean = falsE;
            break;
        }
    }
    for(int i =0; i < boolean.length(); ++i){
        
    }



}