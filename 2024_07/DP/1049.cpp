/*
有一堆石头，用整数数组 stones 表示。其中 stones[i] 表示第 i 块石头的重量。

每一回合，从中选出任意两块石头，然后将它们一起粉碎。假设石头的重量分别为 x 和 y，且 x <= y。那么粉碎的可能结果如下：

如果 x == y，那么两块石头都会被完全粉碎；
如果 x != y，那么重量为 x 的石头将会完全粉碎，而重量为 y 的石头新重量为 y-x。
最后，最多只会剩下一块 石头。返回此石头 最小的可能重量 。如果没有石头剩下，就返回 0。
*/
#include <iostream>
#include <vector>
#include <numeric>  // For std::accumulate

using namespace std;

class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int sum = accumulate(stones.begin(), stones.end(), 0);
        int target = sum / 2;
        vector<bool> dp(target + 1, false);
        dp[0] = true;  // 0重量总是可能的

        for (int stone : stones) {
            for (int j = target; j >= stone; j--) {
                dp[j] = dp[j] || dp[j - stone];
            }
        }

        for (int j = target; j >= 0; j--) {
            if (dp[j]) {
                return sum - 2 * j;  // 找到最接近sum/2的子集重量
            }
        }

        return 0;
    }
};

int main() {
    Solution solution;
    vector<int> stones = {2, 7, 4, 1, 8, 1};
    cout << "The smallest possible weight of the last remaining stone: " << solution.lastStoneWeightII(stones) << endl;
    return 0;
}
