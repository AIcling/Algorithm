/*
给你一个链表的头节点 head ，判断链表中是否有环。
如果链表中有某个节点，可以通过连续跟踪 next 指针再次到达，则链表中存在环。 
为了表示给定链表中的环，评测系统内部使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。注意：pos 不作为参数进行传递 。仅仅是为了标识链表的实际情况。
如果链表中存在环 ，则返回 true 。 否则，返回 false 。
*/
#include <iostream>
#include <unordered_set>

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        std::unordered_set<ListNode*> visited;  // 创建一个哈希表存储访问过的节点

        while (head) {
            if (visited.find(head) != visited.end()) {
                // 如果节点已存在于哈希表中，返回 true
                return true;
            }
            visited.insert(head);  // 否则将节点添加到哈希表中
            head = head->next;  // 移动到下一个节点
        }

        return false;  // 如果遍历完成没有发现环，返回 false
    }
};

int main() {
    // 构建示例链表
    ListNode *head = new ListNode(3);
    ListNode *node1 = new ListNode(2);
    ListNode *node2 = new ListNode(0);
    ListNode *node3 = new ListNode(-4);

    head->next = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = node1; // 创建环

    Solution solution;
    std::cout << "Does the linked list have a cycle? " << (solution.hasCycle(head) ? "Yes" : "No") << std::endl;

    // 释放内存略，由于存在环，此例释放比较复杂，需要特别的处理避免循环释放
    return 0;
}
