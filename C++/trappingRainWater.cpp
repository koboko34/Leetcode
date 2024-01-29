#include <vector>
#include <map>

class Solution {
public:
    int trap(std::vector<int>& height)
    {
        // time complexity: O(n)
        // space complexity: O(1)
        
        int ans = 0;
        int l = 0;
        int r = height.size() - 1;

        int maxLeft = height[l];
        int maxRight = height[r];

        while (l <= r)
        {
            if (maxLeft <= maxRight)
            {
                int res = maxLeft - height[l];
                if (res > 0)
                {
                    ans += res;
                }
                maxLeft = std::max(maxLeft, height[l]);
                l++;
            }
            else
            {
                int res = maxRight - height[r];
                if (res > 0)
                {
                    ans += res;
                }
                maxRight = std::max(maxRight, height[r]);
                r--;
            }
        }
        return ans;
    }
    
    int trapLinear(std::vector<int>& height)
    {
        // time complexity: O(n)
        // space complexity: O(n)
        
        int ans = 0;

        std::vector<int> maxLeft(height.size(), 0);
        std::vector<int> maxRight(height.size(), 0);

        for (int i = 1; i < height.size(); i++)
        {
            maxLeft[i] = std::max(maxLeft[i - 1], height[i - 1]);
        }
        
        for (int i = height.size() - 2; i >= 0; i--)
        {
            maxRight[i] = std::max(maxRight[i + 1], height[i + 1]);
        }

        for (int i = 0; i < height.size(); i++)
        {
            int diff = std::min(maxLeft[i], maxRight[i]) - height[i];
            if (diff <= 0)
            {
                continue;
            }
            ans += diff;
        }
        return ans;
    }
};

int main()
{
    Solution s;
    s.trap(std::vector<int>{5,5,1,7,1,1,5,2,7,6});
}