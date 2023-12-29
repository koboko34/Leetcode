#include <algorithm>

#include "TreeNode.h"

class Solution {
public:
    bool isValidBST(TreeNode* root)
    {
        // time complexity: O(n)
        // space complexity: O(n)
        
        return dfs(root, LONG_MIN, LONG_MAX);
    }

    bool dfs(TreeNode* node, long min, long max)
    {
        if (!node)
        {
            return true;
        }

        if (!(node->val < max && node->val > min))
        {
            return false;
        }
        
        return dfs(node->left, min, node->val) && dfs(node->right, node->val, max);
    }
};