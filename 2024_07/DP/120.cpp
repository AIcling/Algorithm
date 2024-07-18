/*
给定一个三角形 triangle ，找出自顶向下的最小路径和。
每一步只能移动到下一行中相邻的结点上。相邻的结点 在这里指的是 下标 与 上一层结点下标 相同或者等于 上一层结点下标 + 1 的两个结点。
也就是说，如果正位于当前行的下标 i ，那么下一步可以移动到下一行的下标 i 或 i + 1 。
*/

#include <vector>
using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int> > dp = triangle;
        // for(auto& row:dp){
        //     fill(row.begin(),row.end(),0);
        // }
        for(int i=dp.size()-2;i>=0;i--){
            for(int j=0;j<dp[i].size();j++){
                dp[i][j] = min(dp[i+1][j],dp[i+1][j+1]) + dp[i][j];
            }
        }
        return dp[0][0];
    }
};