/*
将两个升序链表合并为一个新的 升序 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) { 
        ListNode *p1 = list1;
        ListNode *p2 = list2;
        ListNode *list3 = new ListNode();
        ListNode *p3 = list3;
        while(p1!=nullptr&&p2!=nullptr){
            if(p1->val<=p2->val){
                p3->next = new ListNode(p1->val);
                p3 = p3->next;
                p1 = p1->next;
            }else{
                p3->next = new ListNode(p2->val);
                p3 = p3->next;
                p2 = p2->next;                
            }
        }
        if(p1!=nullptr){
            p3->next = p1;
        }else{
            p3->next = p2;
        }
        return list3->next;
    }
};