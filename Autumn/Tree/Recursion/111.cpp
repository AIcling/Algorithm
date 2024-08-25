/*
给定一个二叉树，找出其最小深度。
最小深度是从根节点到最近叶子节点的最短路径上的节点数量。
*/
#include <algorithm>
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
    int minDepth(TreeNode* root) {
        if(root==nullptr) return 0;
        std::queue<TreeNode*> q;
        q.push(root);
        int depth = 1;
        TreeNode* node = nullptr;
        while(!q.empty()){
            int size = q.size();
            for(int i=0;i<size;i++){
                node = q.front();
                q.pop();
                if(node->left==nullptr&&node->right==nullptr) return depth;
                if(node->left!=nullptr) q.push(node->left);
                if(node->right!=nullptr) q.push(node->right);
            }
            depth++;
        }
        node = nullptr;
        return depth;
    }
private:
    int findMin(TreeNode* root){
        if(root==nullptr) return 0;
        int lmin = findMin(root->left);
        int rmin = findMin(root->right);
        if(lmin==0&&rmin==0) return 1;
        if(lmin==0) return rmin+1;
        if(rmin==0) return lmin+1;
        return std::min(lmin,rmin)+1;
    }
};