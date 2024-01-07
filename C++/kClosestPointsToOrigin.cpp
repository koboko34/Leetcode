#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<std::vector<int>> kClosest(std::vector<std::vector<int>>& points, int k)
    {
        // time complexity: O(k log n)
        // space complexity: O(k)
        
        std::make_heap(points.begin(), points.end(), compareDist);
        std::vector<std::vector<int>> ans;

        for (size_t i = 0; i < k; i++)
        {
            ans.push_back(points[0]);
            std::pop_heap(points.begin(), points.end(), compareDist);
            points.pop_back();
        }
        
        return ans;
    }

    static bool compareDist(const std::vector<int>& first, const std::vector<int>& second)
    {
        float f = (first[0] * first[0]) + (first[1] * first[1]);
        float s = (second[0] * second[0]) + (second[1] * second[1]);

        return f > s;
    }
};