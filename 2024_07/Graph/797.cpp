/*
给你一个有 n 个节点的 有向无环图（DAG），请你找出所有从节点 0 到节点 n-1 的路径并输出（不要求按特定顺序）
graph[i] 是一个从节点 i 可以访问的所有节点的列表（即从节点 i 到节点 graph[i][j]存在一条有向边）。
*/
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> paths;
        vector<int> path;
        dfs(graph, 0, path, paths);
        return paths;
    }

    void dfs(vector<vector<int>>& graph, int node, vector<int>& path, vector<vector<int>>& paths) {
        path.push_back(node);  // 将当前节点加入路径
        if (node == graph.size() - 1) {  // 如果当前节点是目标节点
            paths.push_back(path);  // 保存路径
        } else {
            // 探索所有邻接节点
            for (int next : graph[node]) {
                dfs(graph, next, path, paths);
            }
        }
        path.pop_back();  // 回溯，从路径中移除当前节点
    }
};

int main() {
    vector<vector<int>> graph = {{1,2}, {3}, {3}, {}};
    Solution solution;
    vector<vector<int>> result = solution.allPathsSourceTarget(graph);
    cout << "All paths from node 0 to node " << graph.size() - 1 << ":" << endl;
    for (const auto& path : result) {
        for (int node : path) {
            cout << node << " ";
        }
        cout << endl;
    }
    return 0;
}
