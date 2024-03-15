#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<std::vector<int>> permuteUnique(std::vector<int>& nums)
    {
        // time complexity: O(n!)
        // space complexity: O(n)
        
        std::vector<std::vector<int>> perms;
        std::vector<int> perm;

        std::sort(nums.begin(), nums.end());

        dfs(nums, perms, perm, 0);
        return perms;
    }

    void dfs(std::vector<int>& nums, std::vector<std::vector<int>>& perms, std::vector<int>& perm, int depth)
    {
        if (nums.size() == 0)
        {
            perms.push_back(perm);
            return;
        }

        int lastVal;
        for (size_t i = 0; i < nums.size(); i++)
        {
            if (i != 0 && lastVal == nums[i])
            {
                continue;
            }
            
            int val = nums[i];
            lastVal = nums[i];
            
            nums.erase(nums.begin() + i);
            perm.push_back(val);
            dfs(nums, perms, perm, depth + 1);
            perm.pop_back();
            nums.insert(nums.begin() + i, val);
        }
    }
};