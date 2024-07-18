/*
给定一个字符串数组 arr，字符串 s 是将 arr 的含有 不同字母 的 子序列 字符串 连接 所得的字符串。

请返回所有可行解 s 中最长长度。

子序列 是一种可以从另一个数组派生而来的数组，通过删除某些元素或不删除元素而不改变其余元素的顺序。
*/
#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int maxLength(vector<string>& arr) {
        string current;
        int maxLen = 0;
        dfs(arr, 0, current, maxLen);
        return maxLen;
    }

private:
    // 定义递归函数，不再使用 std::function
    void dfs(const vector<string>& arr, int index, string& current, int& maxLen) {
        if (index == arr.size()) {
            if (isUnique(current)) {
                maxLen = max(maxLen, static_cast<int>(current.length()));
            }
            return;
        }
        
        // 不包含当前字符串的情况
        dfs(arr, index + 1, current, maxLen);
        
        // 包含当前字符串的情况
        current += arr[index];
        if (isUnique(current)) {  // 只有当添加后仍唯一时，才递归
            dfs(arr, index + 1, current, maxLen);
        }
        // 回溯
        current.resize(current.length() - arr[index].length());
    }

    // 检查字符串是否包含唯一字符
    bool isUnique(const string& s) {
        unordered_set<char> chars;
        for (char c : s) {
            if (chars.count(c)) return false;
            chars.insert(c);
        }
        return true;
    }
};

int main() {
    Solution solution;
    vector<string> arr = {"un", "iq", "ue"};
    cout << "Maximum length of a concatenated string with unique characters: " << solution.maxLength(arr) << endl;
    return 0;
}
