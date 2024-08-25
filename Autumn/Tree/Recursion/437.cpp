/*
给定一个二叉树的根节点 root ，和一个整数 targetSum ，求该二叉树里节点值之和等于 targetSum 的 路径 的数目。
路径 不需要从根节点开始，也不需要在叶子节点结束，但是路径方向必须是向下的（只能从父节点到子节点）。
*/
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
    int res = 0;
    int pathSum(TreeNode* root, int targetSum) {
        if (root == nullptr) return 0;
        std::queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            if(node->left!=nullptr) q.push(node->left);
            if(node->right!=nullptr) q.push(node->right);
            dfs(node,targetSum,0);
        }
        return res;
    }
private:
    void dfs(TreeNode* root, int targetSum,int curnum){
        if (root == nullptr) return;
        curnum += root->val;
        if (curnum == targetSum) res++;
        dfs(root->left, targetSum, curnum);
        dfs(root->right, targetSum, curnum);
    }
};