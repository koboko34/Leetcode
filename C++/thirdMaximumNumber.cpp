#include <vector>
#include <algorithm>

class Solution {
public:
    int thirdMax(std::vector<int>& nums)
    {
        // time complexity: O(n)
        // space complexity: O(1)
        
        std::make_heap(nums.begin(), nums.end(), std::less<int>());

        int max = nums[0];
        int last = nums[0];
        int ans;
        int i = 1;
        while (!nums.empty() && i < 3)
        {
            ans = nums[0];
            std::pop_heap(nums.begin(), nums.end(), std::less<int>());
            nums.pop_back();

            if (ans != last)
            {
                i++;
            }
            last = ans;
        }
        return i >= 3 ? ans : max;
    }
};

int main()
{
    Solution s;
    s.thirdMax(std::vector<int>{2,2,3,1});
}