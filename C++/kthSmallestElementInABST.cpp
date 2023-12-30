#include <stack>

#include "TreeNode.h"

class Solution {
public:
    int kthSmallest(TreeNode* root, int k)
    {
        // time complexity: O(n)
        // space complexity: O(n)
        
        std::stack<TreeNode*> stack;
        TreeNode* node = root;

        while (true)
        {
            while (node)
            {
                stack.push(node);
                node = node->left;
            }

            node = stack.top();
            stack.pop();
            k--;
            if (k == 0)
            {
                return node->val;
            }

            node = node->right;
        }
    }

    int dfs(TreeNode* node, int& k)
    {
        // time complexity: O(n)
        // space complexity: O(n)
        
        if (!node)
        {
            return -1;
        }
        
        int ret = dfs(node->left, k);
        if (ret != -1)
        {
            return ret;
        }

        k--;
        if (k == 0)
        {
            return node->val;
        }
        return dfs(node->right, k);
    }
};