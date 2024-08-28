// 给定一个单链表的头节点  head ，其中的元素 按升序排序 ，将其转换为 平衡二叉搜索树。

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

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
    TreeNode* sortedListToBST(ListNode* head) {
        if (head == nullptr) return nullptr;
        return buildBST(head, nullptr);
    }

private:
    TreeNode* buildBST(ListNode* begin, ListNode* end) {
        if (begin == end) return nullptr;

        ListNode* mid = findMid(begin, end);
        TreeNode* root = new TreeNode(mid->val);

        root->left = buildBST(begin, mid);    
        root->right = buildBST(mid->next, end); 

        return root;
    }

    ListNode* findMid(ListNode* begin, ListNode* end) {
        ListNode* slow = begin;
        ListNode* fast = begin;

        while (fast != end && fast->next != end) {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }
};
