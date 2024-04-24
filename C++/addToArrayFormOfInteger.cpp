#include <vector>

class Solution {
public:
    std::vector<int> addToArrayForm(std::vector<int>& num, int k)
    {
        // time complexity: O(n)
        // space complexity: O(1)
        
        int log = log10(k);

        for (size_t i = 0; i <= log; i++)
        {
            int toAdd = k % 10;
            k /= 10;

            int index = num.size() - i - 1;
            if (index < 0)
            {
                num.insert(num.begin(), toAdd);
                continue;
            }
            
            num[index] += toAdd;
            while (index >= 0 && num[index] > 9)
            {
                num[index] = num[index] % 10;

                if (index == 0)
                {
                    num.insert(num.begin(), 1);
                }
                else
                {
                    num[index - 1] += 1;
                }
                index--;
            }
        }
        return num;
    }
};

int main()
{
    Solution s;
    std::vector<int> vec{2,1,5};
    s.addToArrayForm(vec, 806);
}