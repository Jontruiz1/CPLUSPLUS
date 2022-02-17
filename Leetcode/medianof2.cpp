#include <iostream>
#include <vector>

using namespace std;

int main(){
    std::vector<int> a = {1, 3};
    std::vector<int> b = {2}; 
    cout << findMedianSortedArrays(a, b);

}

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2){
    int m = nums1.size();
    int n = nums2.size();
    int sum = 0;

    for(int i = 0, j = (m+n)-1; i < m+n; i++){



    }
}