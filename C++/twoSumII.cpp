#include <vector>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& numbers, int target)
    {
        // time complexity: O(n)
        // space complexity: O(1)
        
        int l = 0;
        int r = numbers.size() - 1;

        while (true)
        {
            if (numbers[l] + numbers[r] == target)
            {
                return std::vector<int>{l + 1, r + 1};
            }
            else if (numbers[l] + numbers[r] < target)
            {
                l++;
            }
            else
            {
                r--;
            }
        }    
    }
};