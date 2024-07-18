/*
你有一个带有四个圆形拨轮的转盘锁。每个拨轮都有10个数字： '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' 。
每个拨轮可以自由旋转：例如把 '9' 变为 '0'，'0' 变为 '9' 。每次旋转都只能旋转一个拨轮的一位数字。
锁的初始数字为 '0000' ，一个代表四个拨轮的数字的字符串。
列表 deadends 包含了一组死亡数字，一旦拨轮的数字和列表里的任何一个元素相同，这个锁将会被永久锁定，无法再被旋转。
字符串 target 代表可以解锁的数字，你需要给出解锁需要的最小旋转次数，如果无论如何不能解锁，返回 -1 。
*/
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> dead(deadends.begin(), deadends.end());
        queue<pair<string, int>> q;
        unordered_set<string> visited;

        // 如果起始点就是死亡数字或目标是初始位置
        if (dead.count("0000")) return -1;
        if (target == "0000") return 0;

        q.push({"0000", 0});
        visited.insert("0000");

        while (!q.empty()) {
            auto [current, steps] = q.front();
            q.pop();

            // 生成所有可能的下一步状态
            for (int i = 0; i < 4; ++i) {
                for (int d = -1; d <= 1; d += 2) {
                    string next = current;
                    next[i] = (next[i] - '0' + d + 10) % 10 + '0';
                    if (next == target) return steps + 1;
                    if (!dead.count(next) && !visited.count(next)) {
                        visited.insert(next);
                        q.push({next, steps + 1});
                    }
                }
            }
        }

        return -1;
    }
};

int main() {
    Solution solution;
    vector<string> deadends = {"0201","0101","0102","1212","2002"};
    string target = "0202";
    cout << "Minimum turns to unlock: " << solution.openLock(deadends, target) << endl;
    return 0;
}
