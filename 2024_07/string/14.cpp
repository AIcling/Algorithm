/*
编写一个函数来查找字符串数组中的最长公共前缀。
如果不存在公共前缀，返回空字符串 ""。
*/
#include <iostream>
#include <vector>
#include <climits>  // 包含 INT_MAX 的定义
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";  // 如果数组为空，返回空字符串
        int minLength = INT_MAX;
        
        // 找到最短字符串的长度
        for (const string& str : strs) {
            minLength = min(minLength, static_cast<int>(str.size()));
        }

        string result = "";
        for (int i = 0; i < minLength; i++) {  // 遍历每个字符的位置
            char currentChar = strs[0][i];  // 取第一个字符串的字符作为比较基准
            for (const string& str : strs) {  // 比较每个字符串在该位置的字符
                if (str[i] != currentChar) {
                    return result;  // 如果发现不匹配，返回当前已经匹配的最长前缀
                }
            }
            result += currentChar;  // 如果当前位置的字符在所有字符串中都匹配，添加到结果中
        }
        
        return result;  // 如果所有的字符都检查完毕，返回结果
    }
};

int main() {
    Solution solution;
    vector<string> strs = {"flower", "flow", "flight"};
    cout << "Longest common prefix: " << solution.longestCommonPrefix(strs) << endl;
    return 0;
}
