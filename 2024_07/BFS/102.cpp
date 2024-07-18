/*
给你二叉树的根节点 root ，返回其节点值的 层序遍历 。（即逐层地，从左到右访问所有节点）。
*/
#include <iostream>
#include <vector>
#include <queue>

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (!root) return result;
        
        queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty()) {
            int levelSize = q.size();  // 当前层的节点数
            vector<int> currentLevel;
            
            for (int i = 0; i < levelSize; ++i) {
                TreeNode* node = q.front();  // 获取队列前面的节点
                q.pop();
                currentLevel.push_back(node->val);  // 将节点值添加到当前层的列表中
                
                // 将当前节点的子节点加入队列
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            
            result.push_back(currentLevel);  // 将当前层的结果添加到最终结果中
        }
        
        return result;
    }
};

int main() {
    // 测试代码
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20, new TreeNode(15), new TreeNode(7));

    Solution solution;
    vector<vector<int>> result = solution.levelOrder(root);
    
    cout << "Level Order Traversal:" << endl;
    for (const auto& level : result) {
        for (int num : level) {
            cout << num << " ";
        }
        cout << endl;
    }

    // 清理内存
    delete root->right->left;
    delete root->right->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
