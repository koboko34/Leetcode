#include <vector>

class Solution {
public:
    int minPathSum(std::vector<std::vector<int>>& grid)
    {
        // time complexity: O(m * n)
        // space complexity: O(m * n)
        
        int ROWS = grid.size() - 1;
        int COLS = grid[0].size() - 1;

        std::vector<std::vector<int>> paths(ROWS + 1, std::vector<int>(COLS + 1, -1));
        paths[ROWS][COLS] = grid[ROWS][COLS];

        for (int row = ROWS; row >= 0; row--)
        {
            for (int col = COLS; col >= 0; col--)
            {
                if (row > 0 && (paths[row - 1][col] == -1 || paths[row - 1][col] > paths[row][col] + grid[row - 1][col]))
                {
                    paths[row - 1][col] = paths[row][col] + grid[row - 1][col];
                }
                if (col > 0 && (paths[row][col - 1] == -1 || paths[row][col - 1] > paths[row][col] + grid[row][col - 1]))
                {
                    paths[row][col - 1] = paths[row][col] + grid[row][col - 1];
                }
            }
        }
        return paths[0][0];
    }
};

int main()
{
    Solution s;
    s.minPathSum(std::vector<std::vector<int>>{{1,3,1},{1,5,1},{4,2,1}});
}