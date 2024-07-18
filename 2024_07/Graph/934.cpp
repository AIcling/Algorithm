/*
给你一个大小为 n x n 的二元矩阵 grid ，其中 1 表示陆地，0 表示水域。
岛 是由四面相连的 1 形成的一个最大组，即不会与非组内的任何其他 1 相连。grid 中 恰好存在两座岛 。
你可以将任意数量的 0 变为 1 ，以使两座岛连接起来，变成 一座岛 。
返回必须翻转的 0 的最小数目。
*/
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int shortestBridge(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
        vector<pair<int, int>> island;
        queue<pair<int, int>> qu;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    qu.emplace(i, j);
                    grid[i][j] = -1;
                    while (!qu.empty()) {
                        auto [x, y] = qu.front();
                        qu.pop();
                        island.emplace_back(x, y);
                        for (int k = 0; k < 4; k++) {
                            int nx = x + dirs[k][0];
                            int ny = y + dirs[k][1];
                            if (nx >= 0 && ny >= 0 && nx < n && ny < n && grid[nx][ny] == 1) {
                                qu.emplace(nx, ny);
                                grid[nx][ny] = -1;
                            }
                        }
                    }
                    for (auto &&[x, y] : island) {
                        qu.emplace(x, y);
                    }
                    int step = 0;
                    while (!qu.empty()) {
                        int sz = qu.size();
                        for (int i = 0; i < sz; i++) {
                            auto [x, y] = qu.front();
                            qu.pop();
                            for (int k = 0; k < 4; k++) {
                                int nx = x + dirs[k][0];
                                int ny = y + dirs[k][1];
                                if (nx >= 0 && ny >= 0 && nx < n && ny < n) {
                                    if (grid[nx][ny] == 0) {
                                        qu.emplace(nx, ny);
                                        grid[nx][ny] = -1;
                                    } else if (grid[nx][ny] == 1) {
                                        return step;
                                    }
                                }
                            }
                        }
                        step++;
                    }
                }
            }
        }
        return 0;
    }
};

int main() {
    vector<vector<int>> grid = {
        {0, 1},
        {1, 0}
    };
    Solution solution;
    cout << "Minimum number of zeros to flip: " << solution.shortestBridge(grid) << endl;
    return 0;
}
