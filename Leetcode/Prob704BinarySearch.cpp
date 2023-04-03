#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

// binary search for leetcode
int bSearch(const vector<int>& nums, int target) {
    int low = 0, high = nums.size()-1;

    // early exit if there's only one or zero elements
    if(high == 0) return (nums[0] >= target ? 0 : -1);
    else if(high == -1) return -1;

    while(nums[low] < target){
        // update mid based on current highs and lows
        int mid = (high + low) /2;

        // either found the element or update low/high
        if(target == nums[mid]) return mid;
        if(target>nums[mid]) low = mid+1;
        else high = mid- 1;
    }

    // broke out of loop, either it found the element or it's not in the array
    return (nums[low] >= target ? low : -1);
}
vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        size_t numSpells = spells.size();
        size_t numPots = potions.size();
        int mid = potions.size()/2;
        int high = potions.size() -1;
        int low = 0;

        sort(potions.begin(), potions.end());
        vector<int> pairs(numSpells);
        cout << "Potions sorted: ";
        for(int i : potions) cout << i << " ";
        cout << '\n';

        for(int i = 0; i < spells.size(); ++i){
            long long minPot = ceil(success/(double)spells[i]);
            cout << "Min pot: " << minPot << '\n';
            if(potions[numPots-1] < minPot) continue;
            int pos = bSearch(potions, minPot);
            cout << "Curr pos: " << pos << '\n';
            for(int j = pos; j < potions.size(); ++j){
                pairs[i]++;
            }
        }

        return pairs;
    }

int main(){
    vector<int> spells = {15, 14, 39};
    vector<int> potions = {22};
    int success = 224;
    vector<int> result = successfulPairs(spells, potions, success);
    cout << "Pairs: ";
    for(int i : result) cout << i << " ";
}