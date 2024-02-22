#include <vector>

class Solution {
public:
    int maxProfit(std::vector<int>& prices)
    {
        // time complexity: O(n)
        // space complexity: O(1)
        
        int ans = 0;
        int max = prices.size() - 1;

        for (int i = prices.size() - 1; i >= 0; i--)
        {
            if (prices[i] < prices[max])
            {
                ans += prices[max] - prices[i];
                max = i;
            }
            
            if (prices[i] > prices[max])
            {
                max = i;
            }
        }
        return ans;
    }
};