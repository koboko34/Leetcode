#include "ListNode.h"

class Solution
{
public:
    static void reorderList(ListNode* head)
    {
        // time complexity: O(n)
        // space complexity: O(1)
        
        if (head->next == nullptr || head->next->next == nullptr)
            return;
        
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != nullptr)
        {
            fast = fast->next;
            if (fast == nullptr)
            {
                break;
            }
            fast = fast->next;
            slow = slow->next;
        }

        slow = reverse(slow);

        ListNode* front = head;
        ListNode* next;

        while (slow != nullptr)
        {
            if (front->next == slow)
                break;
            
            next = front->next;
            front->next = slow;
            front = next;

            if (slow->next == front)
                break;

            next = slow->next;
            slow->next = front;
            slow = next;
        }
        
        next->next = nullptr;
    }

    static ListNode* reverse(ListNode* head)
    {
        if (head == nullptr)
            return nullptr;
        
        ListNode* cur = head;
        ListNode* prev = nullptr;
        ListNode* next = cur->next;

        while (cur != nullptr)
        {
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }

        return prev;
    }
};

int main()
{
    ListNode* five = new ListNode(5, nullptr);
    ListNode* four = new ListNode(4, five);
    ListNode* three = new ListNode(3, four);
    ListNode* two = new ListNode(2, three);
    ListNode* head = new ListNode(1, two);
    Solution::reorderList(head);
}