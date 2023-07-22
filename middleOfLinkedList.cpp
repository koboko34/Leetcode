#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        int length = 1;
        ListNode* current = head;
        while (true)
        {
            if (current->next == nullptr)
            {
                break;
            }
            current = current->next;
            length++;
        }

        int target = length / 2 + 1;
        int count = 1;
        current = head;

        while (count < target)
        {
            current = current->next;
            count++;
        }
        return current;
    }
};

int main()
{
    ListNode* fifth = new ListNode(5);
    ListNode* fourth = new ListNode(4, fifth);
    ListNode* third = new ListNode(3, fourth);
    ListNode* second = new ListNode(2, third);
    ListNode* first = new ListNode(1, second);

    Solution solution;
    int val = solution.middleNode(first)->val;

    std::cout << val << std::endl;
    
    return 0;
}