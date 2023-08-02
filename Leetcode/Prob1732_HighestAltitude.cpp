#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution{
    public:
    int largestAltitude(vector<int>& gain){
        vector<int> altitude = {0};


        for(int i = 0; i < gain.size(); ++i){
            altitude.push_back(altitude[i] + gain[i]);
        }
        
        //std::sort(altitude.begin(), altitude.end());
        //return altitude[altitude.size()-1];
        return *max_element(altitude.begin(), altitude.end());
    }
};


int main(){
    Solution test;
    vector<int> testerVect = {-5, 1, 5, 0, -7};
    cout << test.largestAltitude(testerVect);
}