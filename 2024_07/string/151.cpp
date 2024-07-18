/*
给你一个字符串 s ，请你反转字符串中 单词 的顺序。

单词 是由非空格字符组成的字符串。s 中使用至少一个空格将字符串中的 单词 分隔开。

返回单词顺序颠倒且单词之间用单个空格连接的结果字符串。

注意：输入字符串 s中可能会存在前导空格、尾随空格或者单词间的多个空格。
返回的结果字符串中，单词间应当仅用单个空格分隔，且不包含任何额外的空格。
*/
#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        istringstream iss(s);
        vector<string> words;
        string word;

        // 使用istringstream分割单词，同时去除多余空格
        while (iss >> word) {
            words.push_back(word);
        }

        // 反转单词顺序
        reverse(words.begin(), words.end());

        // 重新拼接成一个字符串
        string result;
        for (int i = 0; i < words.size(); ++i) {
            if (i > 0) result += " ";
            result += words[i];
        }

        return result;
    }
};

int main() {
    Solution solution;
    string s = "  hello    world!  ";
    cout << "Reversed words: '" << solution.reverseWords(s) << "'" << endl;
    return 0;
}
