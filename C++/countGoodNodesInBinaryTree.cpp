#include "TreeNode.h"

class Solution {
public:
    int goodNodes(TreeNode* root)
    {
        // time complexity: O(n)
        // space complexity: O(n)
        
        return dfs(root, root->val);
    }

    int dfs(TreeNode* node, int max)
    {
        if (!node)
        {
            return 0;
        }
        
        if (node->val >= max)
        {
            return dfs(node->left, node->val) + dfs(node->right, node->val) + 1;
        }

        return dfs(node->left, max) + dfs(node->right, max);
    }
};