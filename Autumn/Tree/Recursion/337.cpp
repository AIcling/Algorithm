/*
小偷又发现了一个新的可行窃的地区。这个地区只有一个入口，我们称之为 root 。
除了 root 之外，每栋房子有且只有一个“父“房子与之相连。一番侦察之后，聪明的小偷意识到“这个地方的所有房屋的排列类似于一棵二叉树”。 
如果 两个直接相连的房子在同一天晚上被打劫 ，房屋将自动报警。
给定二叉树的 root 。返回 在不触动警报的情况下 ，小偷能够盗取的最高金额 。
*/
#include <unordered_map>
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
    int rob(TreeNode* root) {
        std::unordered_map<TreeNode*,int> memory;
        return robSub(root,memory);
    }
private:
    int robSub(TreeNode* root,std::unordered_map<TreeNode*,int>& memory){
        if(root==nullptr) return 0;
        if(memory.find(root) != memory.end()) return memory[root];
        int robCur = root->val;
        if(root->left!=nullptr) robCur += robSub(root->left->left,memory)+robSub(root->left->right,memory);
        if(root->right!=nullptr) robCur += robSub(root->right->left,memory)+robSub(root->right->right,memory);
        int norobCur = 0;
        if(root->left!=nullptr) norobCur += robSub(root->left,memory);
        if(root->right!=nullptr) norobCur += robSub(root->right,memory);
        memory[root] = std::max(robCur,norobCur);
        return std::max(robCur,norobCur);
    }
};