//给定二叉树，判断是否是平衡二叉树
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
    bool isBalanced(TreeNode* root) {
        return (check(root)!=-1);
    }

private:
    int check(TreeNode* root){
        if(root==nullptr) return 0;
        else{
            int a = check(root->left);
            int b = check(root->right);
            if(a==-1||b==-1) return -1;
            if(std::abs(a-b)>1) return -1;
            else return std::max(a,b)+1;
        }
    }
};