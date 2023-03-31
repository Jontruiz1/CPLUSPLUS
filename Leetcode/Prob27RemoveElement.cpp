#include <vector>
#include <iostream>

using namespace std;

int removeElement(vector<int>& nums, int val){
    int neq = 0;
    for(int i = 0; i < nums.size(); ++i){
        if(nums[i] != val) neq++;
        else nums.erase(nums.begin()+(i--));
    }
    return neq;
}

int main(){
    vector<int> test = {3, 2, 2, 3};
    cout << removeElement(test, 3);
    for(int i : test) cout << i;
}