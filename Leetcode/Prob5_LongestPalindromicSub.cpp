#include <string>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

/*given a string s, return the longest palindromic substring in s

a string is palindromic if it reads the same forwards and backwards
*/
class Problem{
public:
    
// Solution based on the expanding around a center point
int expandAroundCenter(const string& s, int left, int right){
    // left and right specify the starting points for 
    for(;left >= 0 && right < s.size() && s[left] == s[right]; left--, right++){}
    return right - left - 1;
}

string longestPalindrome(const string& s){
    if(s.size() < 1) return "";

    int start = 0, end = 0;
    for(int i = 0; i < s.size(); ++i){
        int len1 = expandAroundCenter(s, i, i);
        int len2 = expandAroundCenter(s, i, i+1);
        int len = max(len1, len2);
        len > (end - start) ? start = i - ((len-1)/2), end = i + ((len-1)/2) : 0;
    }
    return s.substr(start, end - start+1);
}

/* My Solution
bool isPalindrome(const string& s){
    // single characters are for sure palindrome
    if(s.size() <= 1) return true;

    for(size_t start = 0, end = s.size()-1; end >= start; end--, start++){
        if(s[end] != s[start]) return false;
    }
    return true;
}

string longestPalindrome(const string& s) {
    size_t inputSize = s.size();
    if(inputSize <= 2 && isPalindrome(s)) return s;
    int longestSize = INT_MIN;
    string result = "";

    for(int i = 0; i < inputSize; ++i){
        for(int j = inputSize; j >= 0; --j){
            string temp = s.substr(i, j);
            int currSize = temp.size();

            if(currSize > longestSize && isPalindrome(temp)){
            
                    longestSize = temp.size();
                    result = temp;
            
            }
        }
    }

    return result;
}
};
*/
// make a function to check if a string is a palindrome in the first place
};




int main(){
    Problem test;
    string longest = test.longestPalindrome("civilwartestingwhetherthatnaptionoranynartionsoconceivedandsodedicatedcanlongendureWeareqmetonagreatbattlefiemldoftzhatwarWehavecometodedicpateaportionofthatfieldasafinalrestingplaceforthosewhoheregavetheirlivesthatthatnationmightliveItisaltogetherfangandproperthatweshoulddothisButinalargersensewecannotdedicatewecannotconsecratewecannothallowthisgroundThebravelmenlivinganddeadwhostruggledherehaveconsecrateditfaraboveourpoorponwertoaddordetractTgheworldadswfilllittlenotlenorlongrememberwhatwesayherebutitcanneverforgetwhattheydidhereItisforusthelivingrathertobededicatedheretotheulnfinishedworkwhichtheywhofoughtherehavethusfarsonoblyadvancedItisratherforustobeherededicatedtothegreattdafskremainingbeforeusthatfromthesehonoreddeadwetakeincreaseddevotiontothatcauseforwhichtheygavethelastpfullmeasureofdevotionthatweherehighlyresolvethatthesedeadshallnothavediedinvainthatthisnationunsderGodshallhaveanewbirthoffreedomandthatgovernmentofthepeoplebythepeopleforthepeopleshallnotperishfromtheeart");
    //string test = "ccc"; 
    //cout << test.substr(0, 3);
    //cout << isPalindrome("bzzb");
    cout << longest;
}