#include <vector>
#include <string>
#include <algorithm>

class Solution {
public:
    std::vector<int> partitionLabels(std::string s)
    {
        // time complexity: O(n)
        // space complexity: O(1)
        
        int lastIndex[26]{-1};
        for (size_t i = 0; i < s.size(); i++)
        {
            lastIndex[s[i] - 'a'] = i;
        }
        
        int size = 0;
        int last = 0;
        std::vector<int> ans;
        for (size_t i = 0; i < s.size(); i++)
        {
            size++;
            last = std::max(last, lastIndex[s[i] - 'a']);
            if (i == last)
            {
                ans.push_back(size);
                size = 0;
            }
        }
        return ans;
    }
    
    std::vector<int> partitionLabelsIntervals(std::string s)
    {
        // time complexity: O(n log n)
        // space complexity: O(n)
        
        std::pair<int, int> freq[26];
        std::fill(std::begin(freq), std::end(freq), std::make_pair(-1, -1));

        int index = 0;
        for (const char c : s)
        {
            std::pair<int, int>& letter = freq[c - 'a'];
            
            if (letter.first == -1)
            {
                letter.first = index;
            }
            letter.second = index;
            index++;
        }

        std::vector<std::pair<int, int>> intervals;
        for (const std::pair<int, int>& pair : freq)
        {
            if (pair.first != -1)
            {
                intervals.push_back(pair);
            }
        }

        std::sort(
            intervals.begin(),
            intervals.end(),
            [](const std::pair<int, int>& a, const std::pair<int, int>& b){ return a.first < b.first; }
        );

        std::vector<std::pair<int, int>> mergedIntervals;
        mergedIntervals.push_back(intervals[0]);
        for (size_t i = 1; i < intervals.size(); i++)
        {
            std::pair<int, int>& lastInterval = mergedIntervals[mergedIntervals.size() - 1];
            if (lastInterval.second >= intervals[i].first)
            {
                lastInterval.second = std::max(lastInterval.second, intervals[i].second);
            }
            else
            {
                mergedIntervals.push_back(intervals[i]);
            }
        }
        
        std::vector<int> ans;
        for (const std::pair<int, int>& pair : mergedIntervals)
        {
            ans.push_back(pair.second - pair.first + 1);
        }
        return ans;
    }
};