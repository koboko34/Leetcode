#include <vector>
#include <string>

class Solution {
public:
    std::vector<std::vector<std::string>> partition(std::string s)
    {
        // time complexity: O(2^n)
        // space complexity: O(n)
        
        std::vector<std::vector<std::string>> combos;
        std::vector<std::string> combo;
        dfs(s, combos, combo, 0);
        return combos;
    }

    bool isPalindrome(const std::string& s)
    {
        int l = 0;
        int r = s.size() - 1;
        while (l < r)
        {
            if (s[l] != s[r])
            {
                return false;
            }
            l++;
            r--;
        }
        return true;
    }

    void dfs(const std::string& s, std::vector<std::vector<std::string>>& combos, std::vector<std::string>& combo, int l)
    {
        if (l >= s.size())
        {
            if (isPalindrome(combo[combo.size() - 1]))
            {
                combos.push_back(combo);
            }
            return;
        }

        if (!combo.empty() && !isPalindrome(combo[combo.size() - 1]))
        {
            return;
        }
        
        for (int r = l; r < s.size(); r++)
        {
            combo.push_back(std::string(s.begin() + l, s.begin() + r + 1));
            dfs(s, combos, combo, r + 1);
            combo.erase(combo.begin() + combo.size() - 1);
        }
    }
};

int main()
{
    Solution s;
    s.partition("aab");
}