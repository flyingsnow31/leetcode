#include "bits/stdc++.h"
#include <vector>
class Solution { //双指针
public:
    int trap(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int leftmax = 0, rightmax = 0;
        int ans = 0;
        while(left < right) {
            leftmax = max(leftmax, height[left]);
            rightmax = max(rightmax, height[right]);
            if(height[left] < height[right]) {
                ans += leftmax - height[left];
                left++;
            }
            else {
                ans += rightmax - height[right];
                right--;
            }
        }
        return ans;
    }
};
class Solution2 { //dp
public:
    int trap(vector<int>& height) {
        int len = height.size();
        vector<int> left(len, 0), right(len, 0);
        for(int i = 1; i < len ;i++) {
            left[i] = max(left[i - 1], height[i - 1]); 
            //cout<<left[i] <<" ";
        }
        //cout<<endl;
        for(int i = len - 2; i >= 0; i--) {
            right[i] = max(right[i + 1], height[i + 1]);
            //cout<<right[i] <<" ";
        }
        //cout<<endl;
        int ans = 0;
        for(int i = 0; i < len ; i++) {
            ans += max(0, min(left[i], right[i]) - height[i]);
        }
        return ans;
    }
};