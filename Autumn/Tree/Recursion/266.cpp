// 给你一棵二叉树的根节点 root ，翻转这棵二叉树，并返回其根节点。
#include <queue>
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
    TreeNode* invertTree(TreeNode* root) {
        // exchange(root);
        std::queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            if(root!=nullptr){
                q.push(root->left);
                q.push(root->right);
                std::swap(root->left,root->right);
            }
        }
        return root;
    }
private:
    void exchange(TreeNode* root){
        if (root==nullptr) return;
        else{
            exchange(root->left);
            exchange(root->right);
            TreeNode* tmp = root->left;
            root->left = root->right;
            root->right = tmp;
            return;
        }
    }
};