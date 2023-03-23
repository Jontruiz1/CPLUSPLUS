#include <vector>

using namespace std;


double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;
        int m = nums1.empty() ? 0 : nums1.size();
        int n = nums2.empty() ? 0 : nums2.size();
        
        int i = 0;
        int j = 0;
        int count = 0;
        double median;
        
        while(count < (m+n)){
            if(i == m){
                result.push_back(nums2[j]);
                j++;
            }
            else if (j ==n){
                result.push_back(nums1[i]);
                i++;
            }
            else if (nums1[i] >= nums2[j]){
                result.push_back(nums2[j]);
                j++;
            }
            else{
                result.push_back(nums1[i]);
                i++;
            }
            count++;
        }
        
        
        median = ((m + n) % 2 == 0 ? ( (result[(m + n) / 2 - 1] + result[(m+n)/2]) / 2.0) : result[(m + n) / 2 ]);
        
        return median;
        
    }