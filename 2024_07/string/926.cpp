/*
如果一个二进制字符串，是以一些 0（可能没有 0）后面跟着一些 1（也可能没有 1）的形式组成的，那么该字符串是 单调递增 的。

给你一个二进制字符串 s，你可以将任何 0 翻转为 1 或者将 1 翻转为 0 。

返回使 s 单调递增的最小翻转次数。
*/
#include <iostream>
#include <vector>
#include <string>
#include <climits>  // 包含 INT_MAX 的定义
using namespace std;

class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int n = s.size();
        // flips0[i]表示从s[0]到s[i-1]全部变为0需要的最小翻转次数
        vector<int> flips0(n + 1, 0);
        // flips1[i]表示从s[i]到s[n-1]全部变为1需要的最小翻转次数
        vector<int> flips1(n + 1, 0);

        // 计算flips0
        for (int i = 1; i <= n; ++i) {
            flips0[i] = flips0[i - 1] + (s[i - 1] == '1' ? 1 : 0);
        }

        // 计算flips1
        for (int i = n - 1; i >= 0; --i) {
            flips1[i] = flips1[i + 1] + (s[i] == '0' ? 1 : 0);
        }

        // 计算将字符串分割在不同位置需要的最小翻转次数
        int minFlips = INT_MAX;
        for (int i = 0; i <= n; ++i) {
            minFlips = min(minFlips, flips0[i] + flips1[i]);
        }

        return minFlips;
    }
};

int main() {
    Solution solution;
    string s = "010110";
    cout << "Minimum flips to make string monotonically increasing: " << solution.minFlipsMonoIncr(s) << endl;
    return 0;
}
