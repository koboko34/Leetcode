#include <string>
#include <vector>

class Solution {
public:
    std::string intToRoman(int num)
    {
        // time complexity: O(n)
        // space comeplexity: O(1)
        
        std::string ans = "";
        std::vector<std::pair<int, std::string>> symbols {
            {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"},
            {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"},
            {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}
        };
        
        for (const std::pair<int, std::string>& symbol : symbols)
        {
            int freq = num / symbol.first;
            num -= freq * symbol.first;

            for (int i = 0; i < freq; i++)
            {
                ans.append(symbol.second);
            }
        }
        return ans;
    }
};

int main()
{
    Solution s;
    s.intToRoman(1994);
}