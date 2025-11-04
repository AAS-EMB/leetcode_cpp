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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> s(nums.begin(), nums.end());

        // Handle the case where the head node needs to be removed
        while (head and s.count(head->val) > 0)
        {
            head = head->next;
        }

        // If the list is empty after removing head nodes, return nullptr
        if (head == nullptr)
        {
            return nullptr;
        }

        // Iterate through the list, removing nodes with values in the set
        ListNode * curr = head;
        while (curr->next)
        {
            if (s.contains(curr->next->val))
            {
                // Skip the next node by updating the pointer
                curr->next = curr->next->next;
            }
            else
            {
                // Move to the next node
                curr = curr->next;
            }
        }

        return head;
    }
};