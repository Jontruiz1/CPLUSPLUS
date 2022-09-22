#include <string>
#include <iostream>

using namespace std;



/*
 * Complete the 'getMaxSubstrings' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. STRING s
 *  2. INTEGER k
 */

bool ispalindrome(string s) {
    string current = s;
    reverse(s.begin(), s.end());

    return (current == s);
}

int getMaxSubstrings(string s, int k) {
    int count = 0;

    for (size_t i = 0; i < s.size(); ++i) {
        for (size_t j = i+(k-1); j < s.size(); ++j) {
            string curr(s.begin() + i, s.begin() + (j+1));

            if (curr.size() >= k && ispalindrome(curr)) {
                count++;
                i++;
            }
        }
    }

    return count;
}

int main()
{
    
    cout << getMaxSubstrings("ababaeocco", 4);

}