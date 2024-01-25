#include "TreeNode.h"
#include <algorithm>

class Solution {
public:
    int maxPathSum(TreeNode* root)
    {
        // time complexity: O(n)
        // space complexity: O(h)
        
        int maxPath = root->val;
        subtreeSum(root, maxPath);
        return maxPath;
    }

    int subtreeSum(TreeNode* node, int& maxPath)
    {
        if (node == nullptr)
        {
            return 0;
        }

        int leftMax = subtreeSum(node->left, maxPath);
        int rightMax = subtreeSum(node->right, maxPath);
        leftMax = std::max(leftMax, 0);
        rightMax = std::max(rightMax, 0);

        maxPath = std::max(maxPath, node->val + leftMax + rightMax);

        return node->val + std::max(leftMax, rightMax);
    }
};

int main()
{
    Solution s;
    TreeNode third(3);
    TreeNode second(2);
    TreeNode first(1, &second, &third);
    s.maxPathSum(&first);
}