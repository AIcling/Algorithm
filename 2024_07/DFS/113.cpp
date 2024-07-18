/*
给你二叉树的根节点 root 和一个整数目标和 targetSum ，
找出所有 从根节点到叶子节点 路径总和等于给定目标和的路径。
*/
#include <vector>
#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> paths;
        vector<int> currentPath;
        findPaths(root, targetSum, currentPath, paths);
        return paths;
    }

private:
    void findPaths(TreeNode* node, int targetSum, vector<int>& currentPath, vector<vector<int>>& paths) {
        if (!node) return;

        currentPath.push_back(node->val); // 添加当前节点到路径
        
        // 检查是否为叶子节点且路径和等于目标和
        if (!node->left && !node->right && node->val == targetSum) {
            paths.push_back(currentPath);
        }
        
        // 递归检查左右子树
        findPaths(node->left, targetSum - node->val, currentPath, paths);
        findPaths(node->right, targetSum - node->val, currentPath, paths);
        
        currentPath.pop_back(); // 回溯，移除当前节点
    }
};

int main() {
    // 构建测试用的树
    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(4, new TreeNode(11, new TreeNode(7), new TreeNode(2)), nullptr);
    root->right = new TreeNode(8, new TreeNode(13), new TreeNode(4, new TreeNode(5), new TreeNode(1)));

    Solution solution;
    int targetSum = 22;
    vector<vector<int>> result = solution.pathSum(root, targetSum);

    // 打印结果
    cout << "Paths with sum " << targetSum << ":" << endl;
    for (auto &path : result) {
        for (int val : path) {
            cout << val << " ";
        }
        cout << endl;
    }

    // 清理内存
    delete root->left->left->left;
    delete root->left->left->right;
    delete root->left->left;
    delete root->left;
    delete root->right->right->left;
    delete root->right->right->right;
    delete root->right->right;
    delete root->right->left;
    delete root->right;
    delete root;

    return 0;
}
