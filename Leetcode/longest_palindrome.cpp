#include <iostream>
#include "is_palindrome.cpp"

using namespace std;

string longest_palindrome(string S) {
        string Sp = '|';
        array PalindromeRadii = [0,...,0]; 
        /*= S with a bogus character (eg. '|') inserted between each character (including outer boundaries)
         // The radius of the longest palindrome centered on each place in S'
        // note: length(S') = length(PalindromeRadii) = 2 × length(S) + 1
        */

        int Center = 0
        int Radius = 0
        
        while (Center < length(Sp)) {
            // At the start of the loop, Radius is already set to a lower-bound for the longest radius.
            // In the first iteration, Radius is 0, but it can be higher.
            
            // Determine the longest palindrome starting at Center-Radius and going to Center+Radius
            while Center-(Radius+1) >= 0 and Center+(Radius+1) < length(S') and S'[Center-(Radius+1)] = S'[Center+(Radius+1)] {
                Radius = Radius+1
            }             
         
            // Save the radius of the longest palindrome in the array
            PalindromeRadii[Center] = Radius
            
            // Below, Center is incremented.
            // If any precomputed values can be reused, they are.
            // Also, Radius may be set to a value greater than 0
            
            OldCenter = Center
            OldRadius = Radius
            Center = Center+1
            // Radius' default value will be 0, if we reach the end of the following loop. 
            Radius = 0 
            while Center <= OldCenter + OldRadius {
                // Because Center lies inside the old palindrome and every character inside
                // a palindrome has a "mirrored" character reflected across its center, we
                // can use the data that was precomputed for the Center's mirrored point. 
                MirroredCenter = OldCenter - (Center - OldCenter)
                MaxMirroredRadius = OldCenter + OldRadius - Center
                if PalindromeRadii[MirroredCenter] < MaxMirroredRadius {
                    PalindromeRadii[Center] = PalindromeRadii[MirroredCenter]
                    Center = Center+1
                }   
                else if PalindromeRadii[MirroredCenter] > MaxMirroredRadius {
                    PalindromeRadii[Center] = MaxMirroredRadius
                    Center = Center+1
                }   
                else { // PalindromeRadii[MirroredCenter] = MaxMirroredRadius
                    Radius = MaxMirroredRadius
                    break  // exit while loop early
                }   
            }      
        }
        
        longest_palindrome_in_S' = 2*max(PalindromeRadii)+1
        longest_palindrome_in_S = (longest_palindrome_in_S'-1)/2
        return longest_palindrome_in_S 
    }
int main(){
    cout << longest_palindrome("ac");

}