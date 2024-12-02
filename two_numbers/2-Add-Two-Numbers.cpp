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
        auto carry = 0;
        auto temp  = new ListNode;
        auto tail  = temp;

        while (l1 or l2 or carry) {
            auto val1 = l1 ? l1->val : 0;
            auto val2 = l2 ? l2->val : 0;

            auto sum   = val1 + val2 + carry;
            auto digit = sum % 10;
            carry      = sum / 10;

            tail->next = new ListNode(digit);
            tail       = tail->next;

            l1 = l1 ? l1->next : nullptr;
            l2 = l2 ? l2->next : nullptr;
        }

        auto result = temp->next;
        delete temp;

        return result;
    }
};