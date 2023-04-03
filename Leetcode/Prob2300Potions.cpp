#include <vector>
#include <cmath>
#include <algorithm>
#include <iostream>

using namespace std;

int bSearch(const vector<int>& nums, int target) {
    int low = 0, high = nums.size()-1;

    // early exit if there's only one or zero elements
    if(high == 0) return (nums[0] >= target ? 0 : -1);
    else if(high == -1) return -1;

    while(nums[low] != target || nums[low] < target){
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

        sort(potions.begin(), potions.end());
        vector<int> pairs(numSpells);

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
    vector<int> spells = {13,22,21,13,11,9,13,35,7,38,10,10,38,19,3,16,13,24,16,27,20,24,32,5,16,35,24,2,25,32,20,22,22,3,35,39,27,26,25,21,27,40,15,17,24,40,35,27,20,40,9,35,27,19,15,34,35,37,17,40,8,3,33,39,29,22,30,1,37,2,16,30,32,31,24,6,34,26,36,4,21,2,29,31,3,27,6,24,40,18};
    vector<int> potions = {33,16,35,14,26,23,23,2,37,23,15,20,25,34,23,29,4,18,26,24,16,37,15,11,33,24,12,13,7,24,3,26,1,3,38,33,19,3,34,22,30,39,18,7,21,4,33,18,39,5,34,14,32,5,20,22,5,25,15};
    int success = 533;
    vector<int> result = successfulPairs(spells, potions, success);
    cout << "Pairs: ";
    for(int i : result) cout << i << " ";
}