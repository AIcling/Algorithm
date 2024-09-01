//给定一个未排序的整数数组 nums ， 返回最长递增子序列的个数 。

#include <algorithm>
#include <vector>

class Solution {
public:
    int findNumberOfLIS(std::vector<int>& nums){
        int n = nums.size();
        if(n==1) return 1;
        std::vector<int> dp(n,1);
        std::vector<int> count(n,1);//nums[i]结尾且长度为dp[i]
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[j]<nums[i]) {
                    if(dp[j]+1>dp[i]){
                        dp[i] = dp[j] + 1;
                        count[i] = count[j];
                    }else if(dp[j]+1==dp[i]){
                        count[i] += count[j];
                    }
                }
            }
        }
        int max_val = *std::max_element(dp.begin(),dp.end());
        int res=0;
        for(int i=0;i<n;i++){
            if(dp[i]==max_val) res+=count[i];
        }
        return res;       
    }
};

int main(void){
    std::vector<int> nums = {1,3,5,4,7};
    Solution solution;
    solution.findNumberOfLIS(nums);
}