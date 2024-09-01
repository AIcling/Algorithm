/*
给定一个数组 prices ，它的第 i 个元素 prices[i] 表示一支给定股票第 i 天的价格。
你只能选择 某一天 买入这只股票，并选择在 未来的某一个不同的日子 卖出该股票。设计一个算法来计算你所能获取的最大利润。
返回你可以从这笔交易中获取的最大利润。如果你不能获取任何利润，返回 0 。
*/
#include <vector>

class Solution {
public:
    int maxProfit(std::vector<int>& prices) {
        int n = prices.size();
        std::vector<std::vector<int> > dp(n,std::vector<int>(2,0));
        //0表示持有股票，1表示不持有股票
        dp[0][0] = -prices[0];
        dp[0][1] = 0;
        for(int i=1;i<n;i++){
            dp[i][0] = std::max(-prices[i],dp[i-1][0]);
            dp[i][1] = std::max(dp[i-1][0]+prices[i],dp[i-1][1]);
        }
        return dp[n-1][1];
    }
};