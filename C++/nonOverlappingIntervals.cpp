#include <vector>
#include <algorithm>

class Solution {
public:
    int eraseOverlapIntervals(std::vector<std::vector<int>>& intervals)
    {
        // time complexity: O(n log n)
        // space complexity: O(n)
        
        if (intervals.size() == 0)
        {
            return 0;
        }
        
        int count = 0;
        std::sort(intervals.begin(), intervals.end(), [](const std::vector<int>& a, const std::vector<int>& b){ return a < b; });

        std::vector<int> last = intervals[0];

        for (size_t i = 1; i < intervals.size(); i++)
        {
            if (intervals[i][0] >= last[1])
            {
                last = intervals[i];
                continue;
            }
            
            if (intervals[i][1] <= last[1])
            {
                last = intervals[i];

            }
            count++;
        }
        return count;
    }
};

int main()
{
    Solution s;
    std::vector<std::vector<int>> intervals {{0,2},{1,3},{2,4},{3,5},{4,6}};
    s.eraseOverlapIntervals(intervals);
}