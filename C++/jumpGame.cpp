#include <vector>

class Solution {
public:
    bool canJump(std::vector<int>& nums)
    {
        // time complexity: O(n)
        // space complexity: O(1)
        
        int target = nums.size() - 1;

        for (int i = target - 1; i >= 0; i--)
        {
            if (i + nums[i] >= target)
            {
                target = i;
            }
        }
        return target == 0;
    }
};