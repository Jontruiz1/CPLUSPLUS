#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for(int i = m, j = 0; i < n + m; ++i, ++j){
            nums1[i] = nums2[j];
        }
        sort(nums1.begin(), nums1.end());
    }
};



int main(){
    Solution test;
    vector<int> test1 = {1, 2, 3, 0, 0, 0};
    vector<int> test2 = {2, 5, 6};
    int m = 3, n = 3;

    test.merge(test1, m, test2, n);

    for(auto i : test1){
        cout << i << endl;
    }
}