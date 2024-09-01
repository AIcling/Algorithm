/*
你是一个专业的小偷，计划偷窃沿街的房屋，每间房内都藏有一定的现金。
这个地方所有的房屋都 围成一圈 ，这意味着第一个房屋和最后一个房屋是紧挨着的。同时，相邻的房屋装有相互连通的防盗系统，如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警 。
给定一个代表每个房屋存放金额的非负整数数组，计算你 在不触动警报装置的情况下 ，今晚能够偷窃到的最高金额。
*/
#include <vector>
#include <algorithm>

class Solution {
public:
    int rob(std::vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        //not steal first
        std::vector<int> dp1(n);
        dp1[0] = 0;
        dp1[1] = nums[1];
        for(int i=2;i<=n-1;i++){
            dp1[i] = std::max(dp1[i-1],(dp1[i-2]+nums[i]));
        }
        //steal first
        std::vector<int> dp2(n);
        dp2[0] = nums[0];
        dp2[1] = nums[0];
        for(int i=2;i<n-1;i++){
            dp2[i] = std::max(dp2[i-1],(dp2[i-2]+nums[i]));
        }
        return std::max(dp1[n-1],dp2[n-2]);
    }
};