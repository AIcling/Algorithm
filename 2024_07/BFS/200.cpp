/*
给你一个由 '1'（陆地）和 '0'（水）组成的的二维网格，请你计算网格中岛屿的数量。
岛屿总是被水包围，并且每座岛屿只能由水平方向和/或竖直方向上相邻的陆地连接形成。
此外，你可以假设该网格的四条边均被水包围。
*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty()) return 0;
        
        int numIslands = 0;
        int rows = grid.size();
        int cols = grid[0].size();
        
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (grid[i][j] == '1') {
                    numIslands++;  // 发现新岛屿
                    grid[i][j] = '0';  // 标记为已访问
                    queue<pair<int, int>> neighbors;
                    neighbors.push({i, j});
                    
                    // BFS
                    while (!neighbors.empty()) {
                        auto [x, y] = neighbors.front();
                        neighbors.pop();
                        
                        // 检查四个方向的邻居
                        if (x > 0 && grid[x - 1][y] == '1') {
                            neighbors.push({x - 1, y});
                            grid[x - 1][y] = '0';  // 标记为已访问
                        }
                        if (x < rows - 1 && grid[x + 1][y] == '1') {
                            neighbors.push({x + 1, y});
                            grid[x + 1][y] = '0';
                        }
                        if (y > 0 && grid[x][y - 1] == '1') {
                            neighbors.push({x, y - 1});
                            grid[x][y - 1] = '0';
                        }
                        if (y < cols - 1 && grid[x][y + 1] == '1') {
                            neighbors.push({x, y + 1});
                            grid[x][y + 1] = '0';
                        }
                    }
                }
            }
        }
        
        return numIslands;
    }
};

int main() {
    vector<vector<char>> grid = {
        {'1', '1', '0', '0', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '1', '0', '0'},
        {'0', '0', '0', '1', '1'}
    };
    Solution solution;
    cout << "Number of islands: " << solution.numIslands(grid) << endl;
    return 0;
}
