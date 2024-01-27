#include <vector>

class Solution {
public:
    double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2)
    {
        // time complexity: O(log min(n, m))
        // space complexity: O(1)
        
        std::vector<int>& first = nums1;
        std::vector<int>& second = nums2;

        if (first.size() > second.size())
        {
            std::swap(first, second);
        }

        int l = 0;
        int r = first.size() - 1;
        int total = first.size() + second.size();
        int half = total / 2;

        while (true)
        {
            int i = floor((float)(l + r) / 2);
            int j = half - i - 2;

            int firstLeft = i >= 0 ? first[i] : INT32_MIN;
            int firstRight = (i + 1) < first.size() ? first[i + 1] : INT32_MAX;
            int secondLeft = j >= 0 ? second[j] : INT32_MIN;
            int secondRight = (j + 1) < second.size() ? second[j + 1] : INT32_MAX;

            if (firstLeft <= secondRight && secondLeft <= firstRight)
            {
                if (total % 2)
                {
                    return std::min(firstRight, secondRight);
                }
                else
                {
                    return (double)(std::max(firstLeft, secondLeft) + std::min(firstRight, secondRight)) / 2;
                }
            }
            else if (firstLeft > secondRight)
            {
                r = i - 1;
            }
            else
            {
                l = i + 1;
            }
        }
    }
};

int main()
{
    Solution s;
    s.findMedianSortedArrays(std::vector<int>{2}, std::vector<int>{});
}