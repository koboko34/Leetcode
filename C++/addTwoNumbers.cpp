#include "ListNode.h"

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        // time complexity: O(n)
        // space complexity: O(n)
        
        ListNode* dummy = new ListNode();
        ListNode* node = dummy;

        bool overflow = false;
        while (l1 || l2 || overflow)
        {
            int v1 = (l1 ? l1->val : 0);
            int v2 = (l2 ? l2->val : 0);
            int total = v1 + v2 + (overflow ? 1 : 0);

            if (total > 9)
            {
                total -= 10;
                overflow = true;
            }
            else
            {
                overflow = false;
            }
            
            node->next = new ListNode(total);
            node = node->next;

            l1 = l1 ? l1->next : l1;
            l2 = l2 ? l2->next : l2;
        }
        return dummy->next;
    }
};

int main()
{
    Solution s;
    ListNode third(3);
    ListNode second(4, &third);
    ListNode l1(2, &second);
    ListNode six(4);
    ListNode five(6, &six);
    ListNode l2(5, &five);
    s.addTwoNumbers(&l1, &l2);
}