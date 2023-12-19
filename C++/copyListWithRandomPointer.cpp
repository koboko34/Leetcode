#include "Node.h"
#include <unordered_map>

class Solution {
public:
    static Node* copyRandomList(Node* head)
    {
        // time complexity: O(n)
        // space complexity: O(n)
        
        if (head == nullptr)
            return nullptr;
        
        std::unordered_map<Node*, Node*> map;

        Node* cur = head;
        while (cur != nullptr)
        {
            map[cur] = new Node(cur->val);
            cur = cur->next;
        }

        cur = head;
        while (cur != nullptr)
        {            
            if (cur->next != nullptr)
                map[cur]->next = map[cur->next];

            if (cur->random != nullptr)
                map[cur]->random = map[cur->random];

            cur = cur->next;
        }

        return map[head];
    }
};

int main()
{
    Node fifth(1);
    Node fourth(10);
    Node third(11);
    Node second(13);
    Node first(7);
    fifth.next = nullptr;
    fifth.random = &first;
    fourth.next = &fifth;
    fourth.random = &third;
    third.next = &fourth;
    third.random = &fifth;
    second.next = &third;
    second.random = &first;
    first.next = &second;
    first.random = nullptr;
    
    Solution::copyRandomList(&first);
}