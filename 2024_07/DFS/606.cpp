/*
给你二叉树的根节点 root ，请你采用前序遍历的方式，将二叉树转化为一个由括号和整数组成的字符串，返回构造出的字符串。

空节点使用一对空括号对 "()" 表示，转化后需要省略所有不影响字符串与原始二叉树之间的一对一映射关系的空括号对。
*/
#include <iostream>
#include <string>

using namespace std;

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
    string tree2str(TreeNode* root) {
        if (!root) return "";

        string result = to_string(root->val);
        if (root->left || root->right) { // 如果存在左孩子或右孩子
            result += "(" + tree2str(root->left) + ")"; // 处理左子树，即使为空也需要添加"()"
        }
        if (root->right) { // 只有当存在右孩子时
            result += "(" + tree2str(root->right) + ")"; // 处理右子树
        }
        return result;
    }
};

int main() {
    // 测试用例
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(4);

    Solution solution;
    cout << "Tree to string: " << solution.tree2str(root) << endl;

    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;
    return 0;
}
