#include "TreeNode.h"

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        // time complexity: O(log n)
        // space complexity: O(1)

        while (true)
        {          
            if (root->val > p->val && root->val > q->val)
            {
                root = root->left;
            }
            else if (root->val < p->val && root->val < q->val)
            {
                root = root->right;
            }
            else
            {
                return root;
            }
        }
    }
};