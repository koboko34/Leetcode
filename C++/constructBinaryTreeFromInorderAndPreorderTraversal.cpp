#include <vector>
#include <unordered_map>

#include "TreeNode.h"

class Solution {
public:
    TreeNode* buildTree(std::vector<int>& preorder, std::vector<int>& inorder)
    {
        // time complexity: O(n)
        // space complexity: O(n)
        
        std::unordered_map<int, int> map;
        for (size_t i = 0; i < inorder.size(); i++)
        {
            map[inorder[i]] = i;
        }

        int preSize = preorder.size();
        int inSize = inorder.size();

        TreeNode* root = build(preorder, 0, preSize - 1, inorder, 0, inSize - 1, map);
        return root;
    }

    TreeNode* build(const std::vector<int>& preorder, int preStart, int preEnd, const std::vector<int>& inorder, int inStart, int inEnd, std::unordered_map<int, int>& map)
    {
        if (preStart > preEnd || inStart > inEnd)
        {
            return nullptr;
        }

        TreeNode* root = new TreeNode(preorder[preStart]);
        int inRoot = map[root->val];
        int numLeft = inRoot - inStart;

        root->left = build(preorder, preStart + 1, preStart + numLeft, inorder, inStart, inRoot - 1, map);
        root->right = build(preorder, preStart + numLeft + 1, preEnd, inorder, inRoot + 1, inEnd, map);

        return root;
    }
};
