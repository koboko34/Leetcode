#include <algorithm>

#include "TreeNode.h"

class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root)
    {
        // time complexity: O(n)
        // space complexity: O(n)
        
        int diameter = 0;
        dfs(root, diameter);

        return diameter;
    }

    int dfs(TreeNode* root, int& max)
    {
        if (root == nullptr)
            return -1;

        int left = dfs(root->left, max);
        int right = dfs(root->right, max);

        max = std::max(max, 2 + left + right);

        return 1 + std::max(left, right);
    }
};