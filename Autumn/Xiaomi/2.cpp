/*
给你两个 非空 的链表，表示两个非负的整数。它们每位数字都是按照 逆序 的方式存储的，并且每个节点只能存储 一位 数字。
请你将两个数相加，并以相同形式返回一个表示和的链表。
你可以假设除了数字 0 之外，这两个数都不会以 0 开头。
*/
struct ListNode
{
    int val;
    ListNode *next;
    ListNode():val(0),next(nullptr){}
    ListNode(int x):val(x),next(nullptr){}
    ListNode(int x,ListNode *next):val(x),next(next){}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *l3 = new ListNode();
        ListNode *p = l3;
        int flag = 0;
        while(l1!=nullptr&&l2!=nullptr){
            int val = l1->val + l2->val + flag;
            if(val>=10){
                flag = 1;
                val -= 10;
            }else{
                flag = 0;
            }
            p->next = new ListNode(val);
            p = p->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        while(l1!=nullptr){
            int val = l1->val + flag;
            if(val>=10){
                flag = 1;
                val -= 10;
            }else{
                flag = 0;
            }
            p->next = new ListNode(val);
            p = p->next;
            l1 = l1->next;
        }
        while(l2!=nullptr){
            int val = l2->val + flag;
            if(val>=10){
                flag = 1;
                val -= 10;
            }else{
                flag = 0;
            }
            p->next = new ListNode(val);
            p = p->next;
            l2 = l2->next;
        }
        if(flag==1) p->next = new ListNode(1);
        return l3->next;
    }
};