#include <vector>
#include <iostream>

using namespace std;

// binary search for leetcode
int bSearch(const vector<int>& nums, int target) {
    int low = 0, high = nums.size()-1;

    // early exit if there's only one or zero elements
    if(high == 0) return (nums[0] == target ? 0 : -1);
    else if(high == -1) return -1;

    while(low < high){
        // update mid based on current highs and lows
        int mid = (high + low) /2;

        // either found the element or update low/high
        if(target == nums[mid]) return mid;
        if(target>nums[mid]) low = mid+1;
        else high = mid- 1;
    }

    // broke out of loop, either it found the element or it's not in the array
    return (nums[low] == target ? low : -1);
}
int main(){
    vector<int> nums{-1, 0, 3, 5, 9 , 12};
    int target = 5;
    cout << bSearch(nums, target) << endl;

    vector<int> second{2, 5};
    int stest = 0;
    cout << bSearch(second, stest);
}