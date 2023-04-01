#include <vector>
#include <iostream>

using namespace std;

int bSearch(vector<int>& nums, int target) {
    int low = 0, high = nums.size()-1;
    if(high == 0) return (nums[0] == target ? 0 : -1);
    int mid = (high + low) /2;

    while(low < high){
        if(target == nums[mid]) return mid;

        if(target > nums[mid]) low = mid+1;
        else high = mid -1;
        mid = (high + low) /2;
    }

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