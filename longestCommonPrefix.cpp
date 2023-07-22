#include <string>
#include <vector>

class Solution {
public:
    std::string longestCommonPrefix(std::vector<std::string>& strs)
    {
        std::string solution = "";
        if (!strs.empty() && !strs[0].empty())
        {
            solution = strs[0];
        }
        
        for (const std::string& str : strs)
        {
            for (size_t i = 0; i < str.size(); i++)
            {
                if (solution[i] != str[i])
                {
                    int count = solution.size() - i;
                    for (size_t j = 0; j < count; j++)
                    {
                        solution.pop_back();
                    }
                    return solution;
                }
                
            }
            
        }
        return "";
    }
};

int main()
{
    std::vector<std::string> strs;
    strs.insert(strs.end(), {"flower","flow","flight"});

    Solution s;
    s.longestCommonPrefix(strs);
}