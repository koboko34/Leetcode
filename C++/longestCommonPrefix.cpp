#include <string>
#include <vector>
#include <stdio.h>

class Solution {
public:
    std::string longestCommonPrefix(std::vector<std::string>& strs)
    {
        if (strs.empty())
            return "";
        
        std::string solution = strs[0];
        
        for (std::string str : strs)
        {
            if (solution == "")
            {
                return "";
            }
            
            if (str.size() < solution.size())
            {
                int count = solution.size() - str.size();
                for (size_t i = 0; i < count; i++)
                {
                    solution.pop_back();
                }
            }
            
            for (size_t i = 0; i < str.size(); i++)
            {
                if (solution == "")
                {
                    return "";
                }

                if (solution[i] != str[i])
                {
                    int count = solution.size() - i;
                    for (size_t j = 0; j < count; j++)
                    {
                        solution.pop_back();
                    }
                    break;
                }
            }
        }
        return solution;
    }
};

int main()
{
    std::vector<std::string> strs;
    strs.insert(strs.end(), {"flower","flow","flight"});

    Solution s;
    printf("%s", s.longestCommonPrefix(strs).c_str());
}