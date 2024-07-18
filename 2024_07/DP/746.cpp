/*
给你一个整数数组 cost ，其中 cost[i] 是从楼梯第 i 个台阶向上爬需要支付的费用。一旦你支付此费用，即可选择向上爬一个或者两个台阶。
你可以选择从下标为 0 或下标为 1 的台阶开始爬楼梯。
请你计算并返回达到楼梯顶部的最低花费。
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n + 1, 0); // 因为可以走一步或两步，所以需要计算到n

        // 初始化
        dp[0] = 0;
        dp[1] = 0;

        // 动态规划
        for (int i = 2; i <= n; i++) {
            dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
        }

        return dp[n]; // 返回到达楼顶的最小成本
    }
};

int main() {
    Solution solution;
    vector<int> cost = {10, 15, 20};
    cout << "Minimum cost to reach the top: " << solution.minCostClimbingStairs(cost) << endl;
    return 0;
}
