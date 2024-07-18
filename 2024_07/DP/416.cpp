/*
给你一个 只包含正整数 的 非空 数组 nums 。请你判断是否可以将这个数组分割成两个子集，使得两个子集的元素和相等。
*/
#include <iostream>
#include <vector>
#include <numeric>  // For std::accumulate

using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        // 如果总和是奇数，不能平分
        if (totalSum % 2 != 0) return false;
        
        int target = totalSum / 2;
        vector<bool> dp(target + 1, false);
        dp[0] = true;  // 空集总和为0，是可能的
        
        for (int num : nums) {
            // 必须从大到小更新，防止同一个数字被多次使用
            for (int j = target; j >= num; j--) {
                dp[j] = dp[j] || dp[j - num];
            }
        }
        
        return dp[target];
    }
};

int main() {
    Solution solution;
    vector<int> nums = {1, 5, 11, 5};
    cout << "Can partition: " << (solution.canPartition(nums) ? "true" : "false") << endl;
    return 0;
}
