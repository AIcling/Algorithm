/*
给你一个字符串 s 、一个字符串 t 。返回 s 中涵盖 t 所有字符的最小子串。如果 s 中不存在涵盖 t 所有字符的子串，则返回空字符串 "" 。
注意：
对于 t 中重复字符，我们寻找的子字符串中该字符数量必须不少于 t 中该字符数量。
如果 s 中存在这样的子串，我们保证它是唯一的答案
*/
#include <iostream>
#include <unordered_map>
#include <string>
#include <climits>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        if (s.empty() || t.empty()) return "";

        // 字符需求统计
        unordered_map<char, int> tCount;
        for (char c : t) {
            tCount[c]++;
        }

        // 初始化滑动窗口和相关变量
        int required = tCount.size();  // 需要的不同字符数量
        int formed = 0;  // 当前窗口中满足需求的不同字符数量
        unordered_map<char, int> windowCounts;  // 窗口中各字符的数量

        // 双指针，左右端点
        int l = 0, r = 0;
        int ans[3] = {INT_MAX, 0, 0};  // 存储结果，形式为{窗口长度, 左边界, 右边界}

        while (r < s.length()) {
            char c = s[r];
            windowCounts[c]++;

            // 检查当前字符在窗口中的计数是否满足需求
            if (tCount.find(c) != tCount.end() && windowCounts[c] == tCount[c]) {
                formed++;
            }

            // 尝试缩小窗口，直到窗口不再有效
            while (l <= r && formed == required) {
                c = s[l];

                // 更新最小窗口
                if (r - l + 1 < ans[0]) {
                    ans[0] = r - l + 1;
                    ans[1] = l;
                    ans[2] = r;
                }

                // 左指针向右移动，更新窗口和状态
                windowCounts[c]--;
                if (tCount.find(c) != tCount.end() && windowCounts[c] < tCount[c]) {
                    formed--;
                }

                l++;
            }

            r++;  // 右指针向右移动
        }

        return ans[0] == INT_MAX ? "" : s.substr(ans[1], ans[0]);
    }
};

int main() {
    Solution solution;
    string s = "ADOBECODEBANC";
    string t = "ABC";
    cout << "Minimum window substring: " << solution.minWindow(s, t) << endl;
    return 0;
}
