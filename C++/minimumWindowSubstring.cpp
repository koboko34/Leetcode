#include <string>
#include <unordered_map>
#include <unordered_set>

class Solution {
public:
    std::string minWindow(std::string s, std::string t)
    {
        // time complexity: O(n + m)
        // space complexity: O(n + m)
        
        std::unordered_map<char, int> map;
        std::unordered_map<char, int> spares;
        std::unordered_set<char> set(t.begin(), t.end());

        for (char c : t)
        {
            map[c]++;
        }

        int l = 0;
        int r = 0;
        std::string ans = "";

        while (r < s.size())
        {
            if (set.find(s[r]) == set.end())
            {
                r++;
                continue;
            }
            
            if (map.find(s[r]) != map.end())
            {
                map[s[r]]--;
                if (map[s[r]] != 0)
                {
                    r++;
                    continue;
                }
                
                map.erase(s[r]);

                while (spares[s[l]] > 0 || set.find(s[l]) == set.end())
                {
                    if (spares[s[l]] > 0)
                    {
                        spares[s[l]]--;
                        l++;
                    }
                    else
                    {
                        l++;
                    }
                }

                if (map.empty() && (ans.size() == 0 || r - l < ans.size()))
                {
                    ans = std::string(s.begin() + l, s.begin() + r + 1);
                }
                r++;
                continue;
            }

            spares[s[r]]++;
            while (spares[s[l]] > 0 || set.find(s[l]) == set.end())
            {
                if (spares[s[l]] > 0)
                {
                    spares[s[l]]--;
                    l++;
                }
                else
                {
                    l++;
                }
            }

            if (map.empty() && ans.size() != 0 && r - l < ans.size())
            {
                ans = std::string(s.begin() + l, s.begin() + r + 1);
            }
            r++;
        }

        while (l < s.size() && (spares[s[l]] > 0 || set.find(s[l]) == set.end()))
        {
            if (spares[s[l]] > 0)
            {
                spares[s[l]]--;
                l++;
            }
            else
            {
                l++;
            }
        }

        if (map.empty() && ans.size() != 0 && r - l < ans.size())
        {
            ans = std::string(s.begin() + l, s.begin() + r);
        }
        return ans;
    }
};

int main()
{
    Solution s;
    s.minWindow("abc", "b");
}