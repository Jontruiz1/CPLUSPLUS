#include <string>
#include <algorithm>


using namespace std;

class Solution{
public:
    string reversePrefix(string word, char ch){
        reverse(word.begin(), word.begin() + word.find_first_of(ch)+1);
        return word;
    }    
};


int main(){
    Solution test;
    test.reversePrefix("help", 'l');

}