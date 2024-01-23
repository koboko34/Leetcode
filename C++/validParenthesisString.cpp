#include <string>

class Solution {
public:
    bool checkValidString(std::string s)
    {
        // time complexity: O(n)
        // space complexity: O(1)
        
        int min = 0;
        int max = 0;
        for (char c : s)
        {            
            if (c == '(')
            {
                min++;
                max++;
            }
            else if (c == ')')
            {
                min--;
                max--;
            }
            else
            {
                max++;
                min--;
            }

            if (max < 0)
            {
                return false;
            }
            if (min < 0)
            {
                min = 0;
            }
        }
        return min == 0;          
    }
};
