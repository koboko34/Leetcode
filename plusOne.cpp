#include <vector>

class Solution {
public:
    std::vector<int> plusOne(std::vector<int>& digits)
    {
        if (digits[digits.size() - 1] != 9)
        {
            digits[digits.size() - 1]++;
            return digits;
        }
        
        int fromEnd = 1;
        do
        {
            digits[digits.size() - fromEnd] = 0;
            if (digits.begin() == digits.end() - fromEnd)
            {
                digits.emplace(digits.begin(), 1);
                return digits;
            }
            else
            {
                fromEnd++;
                if (digits[digits.size() - fromEnd] != 9)
                {
                    digits[digits.size() - fromEnd]++;
                    return digits;
                }
            }
        } while (fromEnd <= digits.size());

        return digits;
    }
};

int main()
{
    std::vector<int> v { 9, 9 };
    
    Solution s;
    s.plusOne(v);
}