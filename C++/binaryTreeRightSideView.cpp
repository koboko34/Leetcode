#include <vector>
#include <queue>

#include "TreeNode.h"

class Solution {
public:
    std::vector<int> rightSideView(TreeNode* root)
    {        
        // time complexity: O(n)
        // space complexity: O(n)
        
        std::vector<int> ans;
        if (!root)
        {
            return ans;
        }

        std::queue<TreeNode*> queue;
        queue.push(root);

        while (!queue.empty())
        {
            int len = queue.size();
            ans.push_back(queue.front()->val);

            for (size_t i = 0; i < len; i++)
            {
                TreeNode* node = queue.front();
                if (node->right)
                {
                    queue.push(node->right);
                }
                if (node->left)
                {
                    queue.push(node->left);
                }
                
                queue.pop();
            }
        }
        return ans;    
    }
};