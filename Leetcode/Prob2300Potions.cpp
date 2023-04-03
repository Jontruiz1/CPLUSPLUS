#include <vector>
#include <cmath>
#include <algorithm>
#include <iostream>

using namespace std;
class Solution{
public:
int bSearch(const vector<int>& nums, int target) {
    int low = 0, high = nums.size()-1;

    // early exit if there's only one or zero elements
    if(high == 0) return (nums[0] >= target ? 0 : -1);
    else if(high == -1) return -1;

    while(nums[low] < target){
        // update mid based on current highs and lows
        int mid = (high + low) /2;

        // either found the element or update low/high
        if(target>nums[mid]) low = mid+1;
        else high = mid- 1;
    }

    // broke out of loop, either it found the element or it's not in the array
    return (nums[low] >= target ? low : -1);
}

void merge(vector<int>& potions, int left, int mid, int right){
    int leftSize = mid - left + 1;
    int rightSize = right - mid;

    vector<int> leftArray(leftSize);
    vector<int> rightArray(rightSize);

    for(int i = 0; i < leftSize; ++i){
        leftArray[i] = potions[left+i];
    }

    for(int j = 0; j < rightSize; ++j){
        rightArray[j] = potions[mid+1+j];
    }

    auto indexOfSubArrayOne
        = 0, // Initial index of first sub-array
        indexOfSubArrayTwo
        = 0; // Initial index of second sub-array
    int indexOfMergedArray
        = left; // Initial index of merged array
 
    // Merge the temp arrays back into array[left..right]
    while (indexOfSubArrayOne < leftSize
           && indexOfSubArrayTwo < rightSize) {
        if (leftArray[indexOfSubArrayOne]
            <= rightArray[indexOfSubArrayTwo]) {
            potions[indexOfMergedArray]
                = leftArray[indexOfSubArrayOne];
            indexOfSubArrayOne++;
        }
        else {
            potions[indexOfMergedArray]
                = rightArray[indexOfSubArrayTwo];
            indexOfSubArrayTwo++;
        }
        indexOfMergedArray++;
    }
    // Copy the remaining elements of
    // left[], if there are any
    while (indexOfSubArrayOne < leftSize) {
        potions[indexOfMergedArray]
            = leftArray[indexOfSubArrayOne];
        indexOfSubArrayOne++;
        indexOfMergedArray++;
    }
    // Copy the remaining elements of
    // right[], if there are any
    while (indexOfSubArrayTwo < rightSize) {
        potions[indexOfMergedArray]
            = rightArray[indexOfSubArrayTwo];
        indexOfSubArrayTwo++;
        indexOfMergedArray++;
    }
}

void mergeSort(vector<int>& potions, int begin, int end){
    if(begin >= end) return;

    int mid = (begin + end) /2;
    mergeSort(potions, begin, mid);
    mergeSort(potions, mid+1, end);
    merge(potions, begin, mid, end);
}


vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        size_t numSpells = spells.size();
        size_t numPots = potions.size();

        if(numPots > 4) mergeSort(potions, 0, potions.size()-1);
        else sort(potions.begin(), potions.end());
        vector<int> pairs(numSpells);

        for(int i = 0; i < spells.size(); ++i){
            long long minPot = ceil(success/(double)spells[i]);
            if(potions[numPots-1] < minPot) continue;
            int pos = bSearch(potions, minPot);
            for(int j = pos; j < potions.size(); ++j){
                pairs[i]++;
            }
        }

        return pairs;
    }
    
};



int main(){
    Solution s;
    vector<int> spells = {13,22,21,13,11,9,13,35,7,38,10,10,38,19,3,16,13,24,16,27,20,24,32,5,16,35,24,2,25,32,20,22,22,3,35,39,27,26,25,21,27,40,15,17,24,40,35,27,20,40,9,35,27,19,15,34,35,37,17,40,8,3,33,39,29,22,30,1,37,2,16,30,32,31,24,6,34,26,36,4,21,2,29,31,3,27,6,24,40,18};
    vector<int> potions = {33,16,35,14,26,23,23,2,37,23,15,20,25,34,23,29,4,18,26,24,16,37,15,11,33,24,12,13,7,24,3,26,1,3,38,33,19,3,34,22,30,39,18,7,21,4,33,18,39,5,34,14,32,5,20,22,5,25,15};
    int success = 533;
    vector<int> result = s.successfulPairs(spells, potions, success);
    cout << "Pairs: ";
    for(int i : result) cout << i << " ";
}