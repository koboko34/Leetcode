#include <vector>

class Solution {
public:
    int maxSubArray(std::vector<int>& nums)
    {
        // time complexity: O(n)
        // space complexity: O(1)
        
        int max = INT32_MIN;
        int sub = 0;

        for (int i : nums)
        {
            if (sub < 0)
            {
                sub = 0;
            }
            sub += i;
            max = std::max(max, sub);
        }
        return max;
    }
};
