/*
给定一个二叉树的 root ，返回 最长的路径的长度 ，这个路径中的 每个节点具有相同值 。 
这条路径可以经过也可以不经过根节点。
两个节点之间的路径长度 由它们之间的边数表示。
*/
#include <queue>
#include <algorithm>
#include <tuple>
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
    int longestUnivaluePath(TreeNode* root) {
        if(root==nullptr) return 0;
        int maxVal = 0;
        std::queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            if(node->left!=nullptr) q.push(node->left);
            if(node->right!=nullptr ) q.push(node->right);
            auto [lval,rval] = findMax(node);
            maxVal = std::max(maxVal,lval+rval);
        }
        return maxVal;
    }
private:
    std::tuple<int,int> findMax(TreeNode* root){
        // if(root==nullptr) return 0;
        if(root->left==nullptr&&root->right==nullptr) return std::make_tuple(0,0);
        int lmax=0,rmax=0;
        if(root->left!=nullptr&&root->left->val==root->val) {
            std::tuple<int,int> l = findMax(root->left);
            auto [ll,lr] = l;
            lmax = std::max(ll,lr)+1;
        }
        if(root->right!=nullptr&&root->right->val==root->val) {
            std::tuple<int,int> r = findMax(root->right);
            auto [rl,rr] = r;
            rmax = std::max(rl,rr)+1;
        }
        return std::make_tuple(lmax,rmax);
    }
};