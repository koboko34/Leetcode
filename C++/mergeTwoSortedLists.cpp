
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2)
    {
        ListNode* head = new ListNode();
        ListNode* tail = head;
        
        if ((list1 && list2 && list1->val < list2->val) || (list1 && !list2))
        {
            head->val = list1->val;
            list1 = list1->next;
        }
        else if (list2)
        {
            head->val = list2->val;
            list2 = list2->next;
        }
        else
        {
            return nullptr;
        }
        
        while (list1 && list2)
        {
            if (list1->val < list2->val)
            {
                ListNode* cur = new ListNode(list1->val);
                tail->next = cur;
                tail = cur;
                list1 = list1->next;
            }
            else
            {
                ListNode* cur = new ListNode(list2->val);
                tail->next = cur;
                tail = cur;
                list2 = list2->next;
            }
        }

        if (list1 == nullptr)
        {
            tail->next = list2;
        }
        else
        {
            tail->next = list1;
        }

        return head;
    }
};