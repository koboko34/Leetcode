#include "TreeNode.h"

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // time complexity: O(n)
        // space complexity: O(n)
        
        if ((p == nullptr && q == nullptr) || (p && q && p->val == q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right)))
        {
            return true;
        }

        return false;
    }
};