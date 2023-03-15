#include <iostream>
#include <vector>

using namespace std;

vector<int> findSubstring(string s, vector<string>& words){
    vector<int>  result = {};
        
        int expected_length = words.size() * words[0].length();

        for(int i = 0; i < s.length() - expected_length+1; ++i){
            int check = 0;
            string curr = s.substr(i, expected_length);
            for(string a : words){
                
                size_t pos = curr.find(a);

                if(pos != string::npos){
                    cout << curr << endl;
                    check++;
                }
                else{
                    break;
                }
            }
            if(check == words.size()){
                result.push_back(i);
            }
        }

        return result;
}

int main(){
    //vector<string> test = {"word","good","best","good"};
    //string stest = "wordgoodgoodgoodbestword";

    //vector<string> test = {"word","good","best","word"};
    //string stest = "wordgoodgoodgoodbestword";

    vector<string> test = {"ab","ba","ba"};
    string stest = "ababaab";
    vector<int> result = findSubstring(stest, test);

    for(int i : result){
        cout << i;
    }
}