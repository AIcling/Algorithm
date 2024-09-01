/*
给你一个整数数组 nums ，找到其中最长严格递增子序列的长度。
子序列 是由数组派生而来的序列，删除（或不删除）数组中的元素而不改变其余元素的顺序。
*/
#include <vector>
#include <algorithm>

class Solution {
public:
    int lengthOfLIS(std::vector<int>& nums) {
        int n = nums.size();
        if(n==1) return 1;
        std::vector<int> dp(n,1);
        dp[0] = 1;
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[j]<nums[i]) dp[i] = std::max(dp[j]+1,dp[i]);
            }
        }
        return *std::max_element(dp.begin(),dp.end());
    }
};