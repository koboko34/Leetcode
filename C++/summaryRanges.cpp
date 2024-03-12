#include <vector>
#include <string>

class Solution {
public:
    std::vector<std::string> summaryRanges(std::vector<int>& nums)
    {
        // time complexity: O(n)
        // space complexity: O(1)
        
        std::vector<std::string> ans;
        if (nums.empty())
        {
            return ans;
        }
        
        std::string s = std::to_string(nums[0]);
        int l = 0;
        for (size_t i = 1; i < nums.size(); i++)
        {            
            if (nums[i] == nums[i - 1] + 1)
            {
                continue;
            }

            if (l != i - 1)
            {
                s += "->" + std::to_string(nums[i - 1]);
            }
            ans.push_back(s);
            s = std::to_string(nums[i]);
            l = i;
        }
        
        if (l != nums.size() - 1)
        {
            s += "->" + std::to_string(nums[nums.size() - 1]);
        }
        ans.push_back(s);
        return ans;
    }
};