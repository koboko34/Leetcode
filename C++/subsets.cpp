#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> subsets(std::vector<int>& nums)
    {
        // time complexity: O(n * 2^n)
        // space complexity: O(n)
        
        std::vector<std::vector<int>> powerSet;
        std::vector<int> subset;

        dfs(powerSet, subset, nums, 0);

        return powerSet;
    }

    void dfs(std::vector<std::vector<int>>& powerSet, std::vector<int>& subset, const std::vector<int>& nums, int depth)
    {
        if (depth >= nums.size())
        {
            powerSet.push_back(subset);
            return;
        }

        subset.push_back(nums[depth]);
        dfs(powerSet, subset, nums, depth + 1);

        subset.pop_back();
        dfs(powerSet, subset, nums, depth + 1);
    }
};