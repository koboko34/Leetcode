#include <vector>
#include <queue>

#include "TreeNode.h"

class Solution {
public:
    std::vector<std::vector<int>> levelOrder(TreeNode* root)
    {
        // time complexity: O(n)
        // space complexity: O(n)
        
        std::vector<std::vector<int>> ans;

        std::queue<TreeNode*> queue;
        queue.push(root);

        while (!queue.empty())
        {
            int len = queue.size();
            std::vector<int> list;

            for (size_t i = 0; i < len; i++)
            {
                TreeNode* node = queue.front();
                queue.pop();
                if (!node)
                    continue;

                queue.push(node->left);
                queue.push(node->right);
                list.push_back(node->val);
            }
            
            if (!list.empty())
            {
                ans.push_back(list);
            }
        }
        return ans;
    }
};