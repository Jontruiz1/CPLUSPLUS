#include <vector>

using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
        
        int x = 0;
        int y = 0;
        for(int i = 0; i < nums.size(); i++){
            for(int j = i+1; j < nums.size(); j++){
                if (nums[i] + nums[j] == target){
                    x = i;
                    y = j;
                    return {x, y};
                }
            }
        }
        return {x,y};
        
    }