#include <vector>

class Solution {
public:
    int jump(std::vector<int>& nums)
    {
        // time complexity: O(n)
        // space complexity: O(1)
        
        int jumps = 0;
        int l = 0;
        int r = 0;

        while (r < nums.size() - 1)
        {
            int newR = 0;
            for (int i = l; i < r + 1; i++)
            {
                newR = std::max(newR, i + nums[i]);
            }
            l = r + 1;
            r = newR;
            jumps++;
        }
        return jumps;
    }
};

int main()
{
    Solution s;
    s.jump(std::vector<int>{2,3,1,1,4});
}