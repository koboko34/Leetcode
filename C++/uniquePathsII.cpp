#include <vector>

class Solution {
public:
    int uniquePathsWithObstacles(const std::vector<std::vector<int>>& grid)
    {
        // time complexity: O(m * n)
        // space complexity: O(n)
        
        int m = grid.size();
        int n = grid[0].size();
        std::vector<long long> row(n, 0);
        row[n - 1] = 1;

        for (int i = m - 1; i >= 0; i--)
        {
            for (int j = n - 1; j >= 0; j--)
            {
                if (grid[i][j] == 1)
                {
                    row[j] = 0;
                }
                else if (j + 1 < n)
                {
                    row[j] += row[j + 1];
                }
            }
        }
        return row[0];
    }
};

int main()
{
    Solution s;
    s.uniquePathsWithObstacles(std::vector<std::vector<int>>{{0,0,0},{0,1,0},{0,0,0}});
}