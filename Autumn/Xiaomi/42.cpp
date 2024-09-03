/*
给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。
*/
#include <vector>
#include <stack>
#include <algorithm>

class Solution {
public:
    int trap(std::vector<int>& height) {
        int n = height.size();
        if(n==0) return 0;
        std::stack<int> stk;
        stk.push(0);
        int sum = 0;
        for(int i=1;i<n;i++){
            while(height[i]>height[stk.top()]){
                int cur = stk.top();
                stk.pop();
                if(stk.size()==0) break;
                int h = std::min(height[i],height[stk.top()]);
                sum += (h-height[cur]) * (i-stk.top()-1);
            }
            stk.push(i);
        }
        return sum;
    }
};