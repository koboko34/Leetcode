#include <vector>
#include <queue>

class Solution {
public:
    int numIslands(std::vector<std::vector<char>>& grid)
    {
        // time complexity: O(m * n)
        // space complexity: O(n)
        
        size_t ROWS = grid.size();
        size_t COLS = grid[0].size();
        int ans = 0;

        for (size_t i = 0; i < ROWS; i++)
        {
            for (size_t j = 0; j < COLS; j++)
            {
                if (grid[i][j] == '1')
                {
                    dfs(grid, i, j, ROWS, COLS);
                    ans++;
                }
            }
        }
        return ans;
    }

    void dfs(std::vector<std::vector<char>>& grid, int x, int y, int rows, int cols)
    {
        if (x < 0 || x >= rows || y < 0 || y >= cols || grid[x][y] != '1')
        {
            return;
        }
        
        grid[x][y] = '2';
        dfs(grid, x + 1, y, rows, cols);
        dfs(grid, x - 1, y, rows, cols);
        dfs(grid, x, y + 1, rows, cols);
        dfs(grid, x, y - 1, rows, cols);
    }
};

int main()
{
    Solution s;
    std::vector<std::vector<char>> grid{{'1','1','0','0','0'},{'1','1','0','0','0'},{'0','0','1','0','0'},{'0','0','0','1','1'}};
    s.numIslands(grid);
}