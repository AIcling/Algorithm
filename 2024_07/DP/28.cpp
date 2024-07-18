/*
给你两个字符串 haystack 和 needle ，请你在 haystack 字符串中找出 needle 字符串的第一个匹配项的下标（下标从 0 开始）。
如果 needle 不是 haystack 的一部分，则返回  -1 。
*/
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.empty()) return 0;
        if (haystack.empty()) return -1;
        
        vector<int> lps = computeLPSArray(needle);
        int i = 0;  // 索引 for haystack
        int j = 0;  // 索引 for needle
        while (i < haystack.size()) {
            if (haystack[i] == needle[j]) {
                i++;
                j++;
                if (j == needle.size()) {
                    return i - j;  // 找到匹配，返回开始位置
                }
            } else if (j > 0) {
                j = lps[j - 1];  // 跳过前缀
            } else {
                i++;
            }
        }
        return -1;  // 未找到匹配
    }

    vector<int> computeLPSArray(string needle) {
        vector<int> lps(needle.size(), 0);
        int len = 0;  // 最长相等前后缀的长度
        int i = 1;
        while (i < needle.size()) {
            if (needle[i] == needle[len]) {
                len++;
                lps[i] = len;
                i++;
            } else {
                if (len != 0) {
                    len = lps[len - 1];
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }
        return lps;
    }
};

int main() {
    Solution solution;
    string haystack = "hello";
    string needle = "ll";
    cout << "Index of the first occurrence of needle in haystack: " << solution.strStr(haystack, needle) << endl;
    return 0;
}
