#include <climits>
#include <algorithm>

#include "TreeNode.h"

class Solution {
public:
    bool isBalanced(TreeNode* root)
    {
        // time complexity: O(n)
        // space complexity: O(n)
        
        if (root == nullptr)
            return true;

        return dfs(root).first;
    }

    std::pair<bool, int> dfs(TreeNode* root)
    {
        if (root == nullptr)
        {
            return std::pair(true, 0);
        }

        std::pair left = dfs(root->left);
        std::pair right = dfs(root->right);

        bool balanced = (left.first && right.first && abs(left.second - right.second) <= 1);

        return std::pair(balanced, 1 + std::max(left.second, right.second));
    }
};

int main()
{
    Solution s;
    TreeNode root;
    TreeNode two;
    TreeNode three;
    TreeNode four;
    TreeNode five;
    TreeNode six;
    TreeNode seven;

    root.left = &two;
    root.right = &three;
    two.left = &four;
    two.right = &five;
    four.left = &six;
    four.right = &seven;

    s.isBalanced(&root);
}