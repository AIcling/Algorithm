/*
有 n 个城市，其中一些彼此相连，另一些没有相连。如果城市 a 与城市 b 直接相连，且城市 b 与城市 c 直接相连，那么城市 a 与城市 c 间接相连。
省份 是一组直接或间接相连的城市，组内不含其他没有相连的城市。
给你一个 n x n 的矩阵 isConnected ，其中 isConnected[i][j] = 1 表示第 i 个城市和第 j 个城市直接相连，而 isConnected[i][j] = 0 表示二者不直接相连。
返回矩阵中 省份 的数量。
*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    void dfs(int city, vector<vector<int>>& isConnected, vector<bool>& visited) {
        visited[city] = true;
        for (int j = 0; j < isConnected[city].size(); j++) {
            if (isConnected[city][j] == 1 && !visited[j]) {
                dfs(j, isConnected, visited);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int provinces = 0;
        vector<bool> visited(isConnected.size(), false);
        
        for (int i = 0; i < isConnected.size(); i++) {
            if (!visited[i]) {
                dfs(i, isConnected, visited);
                provinces++;
            }
        }
        
        return provinces;
    }
};
class Solution2 {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool> visited(n, false);
        int provinces = 0;
        
        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                // BFS from city i
                queue<int> q;
                q.push(i);
                visited[i] = true;
                
                while (!q.empty()) {
                    int current = q.front();
                    q.pop();
                    
                    for (int j = 0; j < n; ++j) {
                        if (isConnected[current][j] == 1 && !visited[j]) {
                            visited[j] = true;
                            q.push(j);
                        }
                    }
                }
                provinces++;  // One complete BFS traversal indicates a new province
            }
        }
        
        return provinces;
    }
};
int main() {
    vector<vector<int>> isConnected = {{1, 1, 0}, {1, 1, 0}, {0, 0, 1}};
    Solution solution;
    cout << "Number of provinces: " << solution.findCircleNum(isConnected) << endl;
    return 0;
}
