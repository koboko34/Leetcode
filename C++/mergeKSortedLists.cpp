#include "ListNode.h"
#include <vector>
#include <algorithm>

class Solution {
public:
    static bool compare(const ListNode* first, const ListNode* second)
    {
        if (!first)
        {
            return true;
        }
        if (!second)
        {
            return false;
        }
        return first->val > second->val;
    }

    ListNode* mergeKLists(std::vector<ListNode*>& lists)
    {
        // time complexity: O(n * k)
        // space complexity: O(1)
        
        if (lists.size() == 0)
            return nullptr;

        std::make_heap(lists.begin(), lists.end(), compare);

        ListNode* head = new ListNode();
        ListNode* tail = head;
        ListNode* prev = nullptr;

        while (!lists.empty())
        {
            if (lists[0] == nullptr)
            {
                std::pop_heap(lists.begin(), lists.end(), compare);
                lists.pop_back();
                continue;
            }

            tail->val = lists[0]->val;
            prev = tail;
            ListNode* newTail = new ListNode();
            prev->next = newTail;
            tail = newTail;

            lists[0] = lists[0]->next;
            if (lists[0] == nullptr)
            {
                std::pop_heap(lists.begin(), lists.end(), compare);
                lists.pop_back();
            }
            else
            {
                std::pop_heap(lists.begin(), lists.end(), compare);
                std::push_heap(lists.begin(), lists.end(), compare);
            }
        }

        if (prev)
        {
            prev->next = nullptr;
        }

        if (head == tail)
        {
            return nullptr;
        }        
        return head;
    }
};

int main()
{
    Solution s;

/*
    ListNode* three = new ListNode(5);
    ListNode* two = new ListNode(4, three);
    ListNode* one = new ListNode(1, two);

    ListNode* six = new ListNode(4);
    ListNode* five = new ListNode(3, six);
    ListNode* four = new ListNode(1, five);

    ListNode* eight = new ListNode(6);
    ListNode* seven = new ListNode(2, eight);
*/
    ListNode* node = nullptr;
    std::vector<ListNode*> lists {node};
    s.mergeKLists(lists);
}