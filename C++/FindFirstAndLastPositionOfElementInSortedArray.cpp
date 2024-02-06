#include <vector>

class Solution {
public:
    std::vector<int> searchRange(std::vector<int>& nums, int target)
    {
        // time complexity: O(log n)
        // space complexity: O(1)
        
        std::vector<int> ans {-1, -1};

        int l = 0;
        int r = nums.size() - 1;
        int mid;

        while (l <= r)
        {
            mid = (l + r) / 2;

            if (nums[mid] == target)
            {
                ans[0] = mid;
                r = mid - 1;
            }
            else if (nums[mid] < target)
            {
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }            
        }

        if (ans[0] == -1)
        {
            return ans;
        }
        
        l = ans[0];
        r = nums.size() - 1;
        while (l <= r)
        {
            mid = (l + r) / 2;

            if (nums[mid] == target)
            {
                ans[1] = mid;
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }            
        }
        return ans;
    }
};