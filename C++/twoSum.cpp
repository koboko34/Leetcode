#include <vector>
#include <unordered_map>
#include <stdio.h>

class Solution {
public:
    std::vector<int> twoSum(const std::vector<int>& nums, int target)
    {
        std::unordered_map<int, int> map;

        for (int i = 0; i < nums.size(); i++)
        {
            if (map.find(target - nums[i]) == map.end())
            {
                map[nums[i]] = i;
            }
            else
            {
                return std::vector<int> {map[target - nums[i]], i};
            }
        }
        return {};
    }
};