/*
给你两棵二叉树 root 和 subRoot 。检验 root 中是否包含和 subRoot 具有相同结构和节点值的子树。
如果存在，返回 true ；否则，返回 false 。
二叉树 tree 的一棵子树包括 tree 的某个节点和这个节点的所有后代节点。tree 也可以看做它自身的一棵子树。
*/
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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        return isSub(root,subRoot);
    }
private:
    bool isSame(TreeNode* t,TreeNode* s){
        if(t==nullptr&&s==nullptr) return true;
        if (t==nullptr||s == nullptr) return false; 
        if(t->val==s->val){
            return isSame(t->left,s->left) && isSame(t->right,s->right);
        }
        return false;
    }
    bool isSub(TreeNode* root, TreeNode* subRoot){
        if(root==nullptr&&subRoot!=nullptr) return false;
        if(isSame(root,subRoot)) return true;
        return isSub(root->left,subRoot) || isSub(root->right,subRoot);
    }
};