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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        auto head   = new ListNode{0};
        auto tail   = head;
        auto carry  = 0;  

        while (l1 or l2 or carry)
        {
            auto value1 = l1 ? l1->val : 0;
            auto value2 = l2 ? l2->val : 0;
            auto sum = value1 + value2 + carry;

            tail->val = sum % 10;
            carry = sum / 10;

            if (l1)
            {
                l1 = l1->next;
            }
            if (l2)
            {
                l2 = l2->next;
            }

            if (l1 or l2 or carry)
            {
                tail->next = new ListNode{0};
                tail = tail->next;
            }
        }

        return head;
    }
};