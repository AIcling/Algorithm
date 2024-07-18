/*
给你一个字符串 s，找到 s 中最长的 回文子串
*/
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    // 用于寻找从left和right开始的最长回文子串
    string expandAroundCenter(const string& s, int left, int right) {
        while (left >= 0 && right < s.length() && s[left] == s[right]) {
            left--;
            right++;
        }
        // 注意substr的第二个参数是长度
        return s.substr(left + 1, right - left - 1);
    }

    string longestPalindrome(string s) {
        if (s.length() < 1) return "";
        string longest = "";

        for (int i = 0; i < s.length(); i++) {
            // 考虑奇数长度的回文
            string p1 = expandAroundCenter(s, i, i);
            // 考虑偶数长度的回文
            string p2 = expandAroundCenter(s, i, i + 1);
            // 选取更长的那个回文子串
            longest = longest.length() < p1.length() ? p1 : longest;
            longest = longest.length() < p2.length() ? p2 : longest;
        }

        return longest;
    }
};

int main() {
    Solution solution;
    string s = "babad";
    cout << "Longest palindromic substring: "
         << solution.longestPalindrome(s) << endl;
    return 0;
}
