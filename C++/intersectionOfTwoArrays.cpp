#include <vector>
#include <unordered_set>

class Solution {
public:
    std::vector<int> intersection(std::vector<int>& nums1, std::vector<int>& nums2)
    {
        // time complexity: O(n log n)
        // space complexity: O(n)
        
        std::vector<int>* first;    
        std::vector<int>* second;

        if (nums1.size() > nums2.size())
        {
            first = &nums1;
            second = &nums2;
        }
        else
        {
            first = &nums2;
            second = &nums1;
        }
        
        std::unordered_set<int> firstSet(first->begin(), first->end());
        std::unordered_set<int> ansSet;

        for (int i : *second)
        {
            if (firstSet.count(i) > 0)
            {
                ansSet.insert(i);
            }
        }
        return std::vector<int>(ansSet.begin(), ansSet.end());
    }
};