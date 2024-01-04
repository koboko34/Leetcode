#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<std::vector<int>> subsetsWithDup(std::vector<int>& nums)
    {
        // time complexity: O(n * 2^n)
        // space complexity: O(n)
        
        std::vector<std::vector<int>> subsets;
        std::vector<int> subset;

        std::sort(nums.begin(), nums.end());

        dfs(subsets, subset, nums, 0);

        return subsets;
    }
    
    void dfs(std::vector<std::vector<int>>& subsets, std::vector<int>& subset, std::vector<int>& nums, int index)
    {
        if (std::find(subsets.begin(), subsets.end(), subset) != subsets.end())
        {
            return;
        }

        subsets.push_back(subset);
        
        for (int i = index; i < nums.size(); i++)
        {
            int val = nums[i];
            subset.push_back(val);
            dfs(subsets, subset, nums, i + 1);
            subset.pop_back();
            dfs(subsets, subset, nums, i + 2);
        }
    }
};

int main()
{
    Solution s;
    std::vector<int> nums = {1, 2, 2};

    s.subsetsWithDup(nums);
}