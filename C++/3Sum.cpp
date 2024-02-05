#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<std::vector<int>> threeSum(std::vector<int>& nums)
    {
        // time complexity: O(n^2)
        // space complexity: O(log n)
        
        std::vector<std::vector<int>> ans;
        std::sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size() - 2; i++)
        {
            if (i > 0 && nums[i] == nums[i - 1])
            {
                continue;
            }

            int l = i + 1;
            int r = nums.size() - 1;
            int sum;

            while (l < r)
            {
                sum = nums[l] + nums[r];
                if (sum + nums[i] < 0)
                {
                    l++;
                }
                else if (sum + nums[i] > 0)
                {
                    r--;
                }
                else
                {
                    ans.push_back(std::vector<int>{nums[i], nums[l], nums[r]});
                    
                    do
                    {
                        l++;
                    }
                    while (l < r && nums[l] == nums[l - 1]);
                }
            }
        }
        return ans;
    }
};

int main()
{
    Solution s;
    s.threeSum(std::vector<int>{-1,0,1,2,-1,-4});
}