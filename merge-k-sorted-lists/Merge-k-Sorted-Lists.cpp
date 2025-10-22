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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty())
        {
            return nullptr;
        }

        return merge(lists, 0, lists.size() - 1);
    }

    ListNode* merge2list(ListNode* l1, ListNode* l2)
    {
        auto result = new ListNode{0};
        auto head = result;

        while (l1 and l2)
        {
            if (l1->val < l2->val)
            {
                head->next = l1;
                l1 = l1->next;
            }
            else
            {
                head->next = l2;
                l2 = l2->next;
            }
            head = head->next;
        }

        head->next = l1 ? l1 : l2;

        return result->next;
    }

    ListNode* merge(vector<ListNode*> & lists, int begin, int end)
    {
       if (begin == end)
       {
            return lists[begin];
       }

       if (begin + 1 == end)
       {
            return merge2list(lists[begin], lists[end]);
       }

       auto mid = begin + (end - begin) / 2;

       auto left  = merge(lists, begin, mid);
       auto right = merge(lists, mid + 1, end);

       return merge2list(left, right); 
    }
};