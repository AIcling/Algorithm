/*
给定正整数 n，找到若干个完全平方数（比如 1, 4, 9, 16, ...）使得它们的和等于 n。你需要让组成和的完全平方数的个数最少。
给你一个整数 n ，返回和为 n 的完全平方数的 最少数量 。
*/
#include <vector>
#include <climits>
#include <iostream>

using namespace std;

class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;  // base case: the least number of perfect squares which sums to 0 is 0.

        // 遍历所有的数来填充 dp 数组
        for (int i = 1; i <= n; ++i) {
            // 计算所有小于等于 i 的完全平方数
            for (int j = 1; j * j <= i; ++j) {
                dp[i] = min(dp[i], dp[i - j * j] + 1);
            }
        }

        return dp[n];
    }
};

int main() {
    Solution solution;
    int n = 12;
    cout << "The least number of perfect squares summing to " << n << " is: " << solution.numSquares(n) << endl;
    return 0;
}
