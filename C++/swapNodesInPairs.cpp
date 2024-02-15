#include "ListNode.h"

class Solution {
public:
    ListNode* swapPairs(ListNode* head)
    {
        // time complexity: O(n)
        // space complexity: O(1)
        
        if (!head || head->next == nullptr)
        {
            return head;
        }
        
        ListNode dummy(0, head);
        ListNode* prev = &dummy;

        while (head && head->next)
        {
            prev->next = head->next;
            head->next = head->next->next;
            prev->next = head;

            prev = head;
            head = head->next;
        }
        return dummy.next;
    }
};