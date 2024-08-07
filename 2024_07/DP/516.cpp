/*
给你一个字符串 s ，找出其中最长的回文子序列，并返回该序列的长度。
子序列定义为：不改变剩余字符顺序的情况下，删除某些字符或者不删除任何字符形成的一个序列。
*/

#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));

        // 单个字符的最长回文子序列长度为1
        for (int i = 0; i < n; i++) {
            dp[i][i] = 1;
        }

        // 填表
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i + 1; j < n; j++) {
                if (s[i] == s[j]) {
                    dp[i][j] = dp[i + 1][j - 1] + 2;
                } else {
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
                }
            }
        }

        return dp[0][n - 1];  // 整个字符串s的最长回文子序列长度
    }
};

int main() {
    Solution solution;
    string s = "bbbab";
    cout << "The length of the longest palindromic subsequence is " << solution.longestPalindromeSubseq(s) << endl;
    return 0;
}
