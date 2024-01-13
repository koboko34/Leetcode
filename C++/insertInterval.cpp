#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> insert(std::vector<std::vector<int>>& intervals, std::vector<int>& newInterval)
    {
        // time complexity: O(n)
        // space complexity: O(n)
        
        int i = 0;
        bool inserted = false;
        while (i < intervals.size())
        {
            if (intervals[i][0] >= newInterval[0])
            {
                intervals.insert(intervals.begin() + i, newInterval);
                inserted = true;
                break;
            }
            i++;
        }

        if (!inserted)
        {
            intervals.push_back(newInterval);
        }

        i = 0;
        int count = 0;
        int start = intervals[0][0];
        int end = intervals[0][1];

        while (i < intervals.size())
        {
            if (intervals[i][0] > end)
            {
                intervals.erase(intervals.begin() + count, intervals.begin() + i);
                intervals.insert(intervals.begin() + count, std::vector<int>{start, end});
                count++;
                i = count;
                start = intervals[i][0];
                end = intervals[i][1];
                i++;
                continue;
            }
            
            end = std::max(end, intervals[i][1]);
            i++;
        }
        
        intervals.erase(intervals.begin() + count, intervals.end());
        intervals.push_back(std::vector<int>{start, end});
        
        return intervals;
    }
};

int main()
{
    Solution s;
    s.insert(std::vector<std::vector<int>>{{1,3}, {6,9}}, std::vector<int>{2, 5});
}