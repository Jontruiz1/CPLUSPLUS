#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int search(const vector<int>& nums, int target) {
            int low = 0, high = nums.size()-1;

    // early exit if there's only one or zero elements
    if(high == 0) return (nums[0] == target ? 0 : -1);
    else if(high == -1) return -1;

    while(low < high){
        int mid = (high + low) /2;
        if(target == nums[mid]) return mid;

        if(target>nums[mid]) low = mid+1;
        else high = mid- 1;
    }

    // broke out of loop, either it found the element or it's not in the array
    return (nums[low] == target ? low : -1);
    }