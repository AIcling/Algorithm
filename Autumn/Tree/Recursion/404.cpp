// 给定二叉树的根节点 root ，返回所有左叶子之和。
#include <queue>
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
    int sumOfLeftLeaves(TreeNode* root) {
        if(root==nullptr) return 0;
        std::queue<TreeNode*> qAll;
        std::queue<TreeNode*> qLeft;
        int val=0;
        qAll.push(root);
        while(!qAll.empty()){
            TreeNode* node = qAll.front();
            qAll.pop();
            if(node->left!=nullptr) {qAll.push(node->left);qLeft.push(node->left);}
            if(node->right!=nullptr) qAll.push(node->right);
        }
        while(!qLeft.empty()){
            TreeNode* node = qLeft.front();
            qLeft.pop();
            if(node->left==nullptr&&node->right==nullptr) val+=node->val;
        }
        return val;
    }
};