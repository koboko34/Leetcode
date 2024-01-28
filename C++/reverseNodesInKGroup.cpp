#include "ListNode.h"

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k)
    {
        // time complexity: O(n)
        // space complexity: O(1)
        
        if (k == 1)
            return head;
        
        ListNode* cur = head;
        ListNode* next = cur->next;
        ListNode* prev = nullptr;

        int len = 0;
        while (cur)
        {
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
            len++;
        }

        cur = prev;
        next = cur->next;
        prev = nullptr;
        ListNode* groupEnd = nullptr;

        for (int offset = len % k; offset > 0; offset--)
        {
            groupEnd = cur;
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        
        ListNode* groupStart = cur;

        while (next)
        {
            groupStart = cur;
            for (int i = 1; i < k; i++)
            {
                cur = cur->next;
            }
            next = cur->next;
            cur->next = groupEnd;
            groupEnd = groupStart;
            cur = next;
        }
        
        return groupStart;    
    }
};

int main()
{
    Solution s;
    ListNode* five = new ListNode(5);
    ListNode* four = new ListNode(4, five);
    ListNode* three = new ListNode(3, four);
    ListNode* two = new ListNode(2, three);
    ListNode* one = new ListNode(1, two);
    s.reverseKGroup(one, 2);
}