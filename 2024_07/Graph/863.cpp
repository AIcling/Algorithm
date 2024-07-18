/*
给定一个二叉树（具有根结点 root）， 一个目标结点 target ，和一个整数值 k ，返回到目标结点 target 距离为 k 的所有结点的值的数组。
答案可以以 任何顺序 返回。
*/
#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <unordered_set>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        unordered_map<TreeNode*, TreeNode*> parentMap; // 存储父节点指针
        markParents(root, nullptr, parentMap); // 填充父节点映射

        queue<TreeNode*> queue; // BFS 队列
        queue.push(target);
        unordered_set<TreeNode*> visited; // 访问过的节点集
        visited.insert(target);
        int currLevel = 0;

        while (!queue.empty()) {
            if (currLevel++ == K) break;
            int size = queue.size();
            for (int i = 0; i < size; i++) {
                TreeNode* node = queue.front(); queue.pop();
                if (node->left && visited.find(node->left) == visited.end()) {
                    queue.push(node->left);
                    visited.insert(node->left);
                }
                if (node->right && visited.find(node->right) == visited.end()) {
                    queue.push(node->right);
                    visited.insert(node->right);
                }
                TreeNode* parent = parentMap[node];
                if (parent && visited.find(parent) == visited.end()) {
                    queue.push(parent);
                    visited.insert(parent);
                }
            }
        }

        vector<int> result;
        while (!queue.empty()) {
            TreeNode* node = queue.front(); queue.pop();
            result.push_back(node->val);
        }
        return result;
    }

private:
    void markParents(TreeNode* node, TreeNode* parent, unordered_map<TreeNode*, TreeNode*>& parentMap) {
        if (!node) return;
        parentMap[node] = parent;
        markParents(node->left, node, parentMap);
        markParents(node->right, node, parentMap);
    }
};

int main() {
    // 创建示例树和目标
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);
    
    Solution solution;
    vector<int> result = solution.distanceK(root, root->left, 2);

    // 输出结果
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
