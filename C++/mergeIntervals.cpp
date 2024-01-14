#include <vector>
#include <algorithm>

class Solution {
public:    
    std::vector<std::vector<int>> merge(std::vector<std::vector<int>>& intervals)
    {
        // time complexity: O(n log n)
        // space complexity: O(n)
        
        if (intervals.size() == 0)
        {
            return intervals;
        }

        std::sort(intervals.begin(), intervals.end(), [](const std::vector<int>& a, const std::vector<int>& b){ return a < b; });
        
        std::vector<std::vector<int>> ans;
        ans.push_back(intervals[0]);

        for (size_t i = 1; i < intervals.size(); i++)
        {
            std::vector<int>& lastInterval = ans[ans.size() - 1];
            if (lastInterval[1] >= intervals[i][0])
            {
                lastInterval[1] = std::max(lastInterval[1], intervals[i][1]);
            }
            else
            {
                ans.push_back(intervals[i]);
            }
        }

        return ans;
    }
};