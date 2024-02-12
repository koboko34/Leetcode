#include <string>
#include <unordered_map>

class Solution {
public:
    std::string convert(std::string s, int numRows)
    {
        // time complexity: O(n)
        // space complexity: O(1)
        
        if (numRows == 1)
        {
            return s;
        }
        
        std::string ans;
        int offset;
        for (size_t i = 0; i < numRows; i++)
        {
            offset = (numRows - 1) * 2;
            for (size_t j = i; j < s.size(); j += offset)
            {
                ans += s[j];
                if (i > 0 && i < numRows - 1 && j + offset - 2 * i < s.size())
                {
                    ans += s[j + offset - 2 * i];
                }
            }
        }
        return ans;
    }
};