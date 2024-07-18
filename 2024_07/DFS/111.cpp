/**
给定一个二叉树，找出其最小深度。

最小深度是从根节点到最近叶子节点的最短路径上的节点数量
 */
#include <algorithm>  // For std::min
#include <climits>     // For std::numeric_limits
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int minDepth(TreeNode* root) {
        // 空节点的深度为0
        if (root == nullptr) {
            return 0;
        }

        // 叶子节点的深度为1
        if (root->left == nullptr && root->right == nullptr) {
            return 1;
        }

        // 初始化一个很大的数，用于找最小值
        int minDepthValue = INT_MAX;

        // 如果左子树非空，递归计算其最小深度
        if (root->left != nullptr) {
            minDepthValue = std::min(minDepth(root->left), minDepthValue);
        }

        // 如果右子树非空，递归计算其最小深度
        if (root->right != nullptr) {
            minDepthValue = std::min(minDepth(root->right), minDepthValue);
        }

        // 返回最小深度加上根节点层
        return minDepthValue + 1;
    }
};
