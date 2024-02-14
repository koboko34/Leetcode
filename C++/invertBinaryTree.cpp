#include "TreeNode.h"
#include <algorithm>

class Solution {
public:
    TreeNode* invertTree(TreeNode* root)
    {
        // time complexity: O(n)
        // space complexity: O(n)
        
        if (root)
        {
            std::swap(root->left, root->right);
            invertTree(root->left);
            invertTree(root->right);
        }
        return root;
    }
};