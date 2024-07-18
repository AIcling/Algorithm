/*
给你一个整数数组 nums ，找到其中最长严格递增子序列的长度。
子序列 是由数组派生而来的序列，删除（或不删除）数组中的元素而不改变其余元素的顺序。
例如，[3,6,2,7] 是数组 [0,3,1,6,2,2,7] 的子序列
*/

#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.empty()) return 0;
        int n = nums.size();
        vector<int> dp(n, 1);  // 初始化dp数组，每个元素至少可以单独成为一个子序列
        int max_len = 1;

        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[j] < nums[i]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            max_len = max(max_len, dp[i]);  // 更新最长递增子序列长度
        }

        return max_len;
    }
};

int main() {
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
    Solution solution;
    cout << "The length of the longest increasing subsequence is: " << solution.lengthOfLIS(nums) << endl;
    return 0;
}
