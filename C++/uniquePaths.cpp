#include <vector>

class Solution {
public:
    int uniquePaths(int m, int n)
    {
        // time complexity: O(m * n)
        // space complexity: O(n)
        
        std::vector<int> row(n, 1);
        for (int i = m - 2; i >= 0; i--)
        {
            std::vector<int> newRow(n, 1);
            for (int j = n - 2; j >= 0; j--)
            {
                newRow[j] = row[j] + newRow[j + 1];
            }
            row = newRow;
        }
        return row[0];
    }
};

int main()
{
    Solution s;
    s.uniquePaths(3, 7);
}