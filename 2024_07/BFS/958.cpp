/*
给你一棵二叉树的根节点 root ，请你判断这棵树是否是一棵 完全二叉树 。
在一棵 完全二叉树 中，除了最后一层外，所有层都被完全填满，并且最后一层中的所有节点都尽可能靠左。
最后一层（第 h 层）中可以包含 1 到 2h 个节点。
*/
#include <iostream>
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
    bool isCompleteTree(TreeNode* root) {
        if (!root) return true;

        queue<TreeNode*> q;
        q.push(root);
        bool end = false;  // 标记是否遇到了第一个不完整的节点

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            if (!node->left) {
                end = true;  // 如果没有左孩子，后续节点必须都没有子节点
            } else {
                if (end) return false;  // 如果已经是不完整状态，还有左孩子，那么不是完全二叉树
                q.push(node->left);
            }

            if (!node->right) {
                end = true;  // 如果没有右孩子，后续节点必须都没有子节点
            } else {
                if (end) return false;  // 如果已经是不完整状态，还有右孩子，那么不是完全二叉树
                q.push(node->right);
            }
        }

        return true;  // 如果能正常结束循环，说明是完全二叉树
    }
};

int main() {
    // 构建一个完全二叉树
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2, new TreeNode(4), new TreeNode(5));
    root->right = new TreeNode(3, new TreeNode(6), nullptr);

    Solution solution;
    cout << "Is the tree a complete binary tree? " << (solution.isCompleteTree(root) ? "Yes" : "No") << endl;

    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right->left;
    delete root->right;
    delete root;

    return 0;
}
