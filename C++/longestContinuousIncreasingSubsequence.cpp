#include <vector>

class Solution {
public:
    int findLengthOfLCIS(std::vector<int>& nums)
    {
        // time complexity: O(n)
        // space complexity: O(1)
        
        int ans = 1;
        int l = 0;
        int r = 1;

        while (r < nums.size())
        {
            if (nums[r] > nums[r - 1])
            {
                ans = std::max(ans, r - l + 1);
            }
            else
            {
                l = r;
            }
            r++;
        }
        return ans;
    }
};