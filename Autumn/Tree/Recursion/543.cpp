/*
给你一棵二叉树的根节点，返回该树的 直径 。
二叉树的 直径 是指树中任意两个节点之间最长路径的 长度 。这条路径可能经过也可能不经过根节点 root 。
两节点之间路径的 长度 由它们之间边数表示。
*/
#include <algorithm>
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
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        calmax(root,diameter);
        return diameter;
    }

private:
    int calmax(TreeNode* root,int& diameter){
        if(root==nullptr) return 0;
        int ldepth = calmax(root->left,diameter);
        int rdepth = calmax(root->right,diameter);
        diameter = std::max(ldepth+rdepth,diameter);
        return std::max(ldepth,rdepth)+1;
    }
};