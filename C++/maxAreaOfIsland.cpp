#include <vector>
#include <queue>

class Solution {
public:
    int maxAreaOfIsland(std::vector<std::vector<int>>& grid)
    {
        // time complexity: O(m * n)
        // space complexity: O(m * n)
        
        const int ROWS = grid.size();
        const int COLS = grid[0].size();
        
        int maxArea = 0;

        for (size_t i = 0; i < ROWS; i++)
        {
            for (size_t j = 0; j < COLS; j++)
            {
                if (grid[i][j] == -1)
                {
                    continue;
                }
                else if (grid[i][j] == 0)
                {
                    grid[i][j] = -1;
                    continue;
                }

                int area = 0;
                std::queue<std::pair<int, int>> queue;
                queue.push({i, j});
                while (!queue.empty())
                {
                    std::pair<int, int> p = queue.front();
                    queue.pop();

                    if (grid[p.first][p.second] == -1)
                    {
                        continue;
                    }
                    else if (grid[p.first][p.second] == 0)
                    {
                        grid[p.first][p.second] = -1;
                        continue;
                    }
                    
                    grid[p.first][p.second] = -1;
                    area++;

                    if (p.first > 0)
                    {
                        queue.push({p.first - 1, p.second});
                    }
                    if (p.first < ROWS - 1)
                    {
                        queue.push({p.first + 1, p.second});
                    }
                    if (p.second > 0)
                    {
                        queue.push({p.first, p.second - 1});
                    }
                    if (p.second < COLS - 1)
                    {
                        queue.push({p.first, p.second + 1});
                    }
                }
                maxArea = std::max(maxArea, area);
            }
        }
        return maxArea;
    }
};