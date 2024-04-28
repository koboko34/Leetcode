#include <vector>

class Solution {
public:
    int minSubArrayLen(int target, std::vector<int>& nums)
    {
        // time complexity: O(n)
        // space complexity: O(1)
        
        int l = 0;
        int r = 0;
        unsigned int sum = 0;
        int ans = INT32_MAX;
        bool found = false;

        for (int r = 0; r < nums.size(); r++)
        {
            sum += nums[r];
            while (sum >= target)
            {
                found = true;
                ans = std::min(ans, r - l + 1);
                sum -= nums[l];
                l++;
            }
        }
        return found ? ans : 0;
    }
};

int main()
{
    Solution s;
    std::vector<int> arr {1,1,1,1,1,3,2};
    s.minSubArrayLen(5, arr);
}