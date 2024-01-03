#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> permute(std::vector<int>& nums)
    {
        // time complexity: O(n!)
        // space complexity: O(n)
        
        std::vector<std::vector<int>> permutations;
        std::vector<int> perm;

        perm.reserve(nums.size());

        dfs(permutations, perm, nums);

        return permutations;
    }

    void dfs(std::vector<std::vector<int>>& permutations, std::vector<int>& perm, std::vector<int>& nums)
    {
        if (nums.size() == 0)
        {
            permutations.push_back(perm);
            return;
        }

        for (int i = 0; i < nums.size(); i++)
        {
            int val = nums[i];
            
            perm.push_back(val);
            nums.erase(nums.begin() + i);
            dfs(permutations, perm, nums);
            nums.insert(nums.begin() + i, val);
            perm.pop_back();
        }
    }
};
