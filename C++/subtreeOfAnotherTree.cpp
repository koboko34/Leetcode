#include "TreeNode.h"

class Solution {
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot)
    {
        // time complexity: O(n*m)
        // space complexity: O(n)
        
        if (subRoot == nullptr)
        {
            return true;
        }
        if (root == nullptr)
        {
            return false;
        }
        if (isSameTree(root, subRoot))
        {
            return true;
        }

        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }

    bool isSameTree(TreeNode* root, TreeNode* subRoot)
    {
        if (!root && !subRoot)
        {
            return true;
        }
        if (!root || !subRoot || root->val != subRoot->val)
        {
            return false;
        }
        return isSameTree(root->left, subRoot->left) && isSameTree(root->right, subRoot->right);
    }
};