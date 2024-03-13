#include <vector>

class Solution {
public:
    std::vector<int> getRow(int rowIndex)
    {
        // time complexity: O(n)
        // space complexity: O(n)
        
        std::vector<int> row(1, 1);

        for (size_t i = 0; i < rowIndex; i++)
        {
            std::vector<int> nextRow(rowIndex + 1, 0);
            for (size_t j = 0; j <= i; j++)
            {
                nextRow[j] += row[j];
                nextRow[j + 1] += row[j];
            }
            row = nextRow;
        }
        
        return row;
    }
};

int main()
{
    Solution s;
    s.getRow(4);
}