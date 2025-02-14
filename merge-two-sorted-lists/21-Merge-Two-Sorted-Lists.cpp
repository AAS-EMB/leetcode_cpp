/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1 == nullptr) return l1;
        if (list2 == nullptr) return l2;

        ListNode *head = nullptr, *cur = nullptr;
        ListNode *p1 = list1, *p2 = list2;
        
        while (p1 not_eq nullptr and p2 not_eq nullptr) {
            if(head == nullptr) {
                if(p1->val <= p2->val) {
                    head = cur = p1;
                    p1   = p1->next;
                } else {
                    head = cur = p2;
                    p2   = p2->next;
                }
            } else {
                if(p1->val <= p2->val) {
                    cur->next = p1;
                    cur       = p1;
                    p1        = p1->next;
                } else {
                    cur->next = p2;
                    cur       = p2;
                    p2        = p2->next;
                }
            }
        }

        if(p1 not_eq nullptr) cur->next = p1;
        if(p2 not_eq nullptr) cur->next = p2;

        return head;
    }
};