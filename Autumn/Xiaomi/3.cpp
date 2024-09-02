// 给定一个字符串 s ，请你找出其中不含有重复字符的 最长 子串的长度。

#include <string>
#include <unordered_map>
#include <algorithm>

class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        std::unordered_map<char,int> CharIndex;
        int maxLength = 0;
        int left = 0;
        for(int right=0;right<s.length();right++){
            char c =s[right];
            if(CharIndex.find(c)!=CharIndex.end()) left = std::max(left,CharIndex[c]+1);
            CharIndex[c] = right;
            maxLength = std::max(maxLength,right-left+1);
        }
        return maxLength;
    }
};