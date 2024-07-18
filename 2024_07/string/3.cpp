/*
给定一个字符串 s ，请你找出其中不含有重复字符的最长子串的长度。
*/
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> charIndexMap;  // 存储字符及其最新位置
        int maxLength = 0;  // 最长子串的长度
        int left = 0;  // 滑动窗口的左边界

        for (int right = 0; right < s.length(); right++) {
            if (charIndexMap.find(s[right]) != charIndexMap.end()) {
                // 如果字符已经存在，更新左边界到重复字符的下一个位置
                left = max(left, charIndexMap[s[right]] + 1);
            }
            charIndexMap[s[right]] = right;  // 更新字符的位置
            maxLength = max(maxLength, right - left + 1);  // 更新最长子串的长度
        }

        return maxLength;
    }
    string longestSubstringWithoutRepeating(string s) {
        unordered_map<char, int> charIndexMap;
        int maxLength = 0;
        int start = 0;
        int left = 0;

        for (int right = 0; right < s.length(); right++) {
            if (charIndexMap.find(s[right]) != charIndexMap.end()) {
                left = max(left, charIndexMap[s[right]] + 1);
            }
            charIndexMap[s[right]] = right;
            if (right - left + 1 > maxLength) {
                maxLength = right - left + 1;
                start = left;
            }
        }

        return s.substr(start, maxLength);
    }
};

int main() {
    Solution solution;
    string s = "abcabcbb";
    cout << "Length of the longest substring without repeating characters: "
         << solution.lengthOfLongestSubstring(s) << endl;
    return 0;
}