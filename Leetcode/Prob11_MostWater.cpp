#include <iostream>
#include <vector>
#include <cmath>

using namespace std;



int maxArea(vector<int>& height){
    // i understand it's an area problem
    int maxarea = 0;

    // get the leftmost num, the ith position? x1?
    int left = 0;

    // get the right most num, the size - 1, x2?
    int right = height.size() - 1;


    while (left < right){
        // getting the width makes sense, just the distance
        // between the x1 and x2
       int width = right - left;

       // it's like saying f(left), which gives you the y value at this pos
       // so you're taking the smallest height and multiplying it by width
       maxarea = max(maxarea, min(height[left], height[right]) * width);
       if(height[left] <= height[right]){
        left++;
       }
       else{
        right--;
       }
    }

    return maxarea;
}

int main(){
  vector<int> height = {1, 1};
  cout << "maxarea: " << maxArea(height);  

  return 0;

}