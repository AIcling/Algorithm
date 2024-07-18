/*
给你两个字符串 s 和 t ，统计并返回在 s 的 子序列 中 t 出现的个数，结果需要对 109 + 7 取模。
*/
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int numDistinct(string s, string t) {
        int m = s.size(), n = t.size();
        vector<vector<long long>> dp(m + 1, vector<long long>(n + 1, 0));
        const int MOD = 1e9 + 7;
        
        for (int i = 0; i <= m; i++)
            dp[i][0] = 1;  // 任何字符串包含空字符串的子序列有1种方式

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (s[i - 1] == t[j - 1])
                    dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % MOD;
                else
                    dp[i][j] = dp[i - 1][j] % MOD;
            }
        }

        return dp[m][n];
    }
};

int main() {
    Solution solution;
    string s = "babgbag";
    string t = "bag";
    cout << "Number of distinct subsequences: " << solution.numDistinct(s, t) << endl;
    return 0;
}
