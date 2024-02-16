#include <vector>
#include <string>
#include <unordered_map>

class Solution {
public:
    std::vector<std::string> letterCombinations(std::string digits)
    {
        // time complexity: O(n * 4^n)
        // space complexity: O(n)
        
        std::vector<std::string> combos;
        std::string combo;

        dfs(combos, combo, digits, 0);

        return combos;
    }

    std::unordered_map<char, std::string> digitMap {
        {'2', "abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"}
    };

    void dfs(std::vector<std::string>& combos, std::string& combo, const std::string& digits, int index)
    {
        if (index >= digits.size())
        {
            if (combo.size() > 0)
            {
                combos.push_back(combo);
            }
            return;
        }
        
        for (char c : digitMap[digits[index]])
        {
            combo.push_back(c);
            dfs(combos, combo, digits, index + 1);
            combo.pop_back();
        }
    }
};