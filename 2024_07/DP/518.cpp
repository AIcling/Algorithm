/*
给你一个整数数组 coins 表示不同面额的硬币，另给一个整数 amount 表示总金额。
请你计算并返回可以凑成总金额的硬币组合数。如果任何硬币组合都无法凑出总金额，返回 0 。
假设每一种面额的硬币有无限个。 
题目数据保证结果符合 32 位带符号整数。
*/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> dp(amount + 1, 0);
        dp[0] = 1;
        for (auto coin : coins) {  // 首先遍历硬币
            for (int i = coin; i <= amount; i++) {  // 然后遍历金额
                dp[i] += dp[i - coin];
            }
        }
        return dp[amount];
    }
};
int main(void){
    Solution solution;
    
}