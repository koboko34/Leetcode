#include <vector>
#include <unordered_set>

class Solution {
public:
    struct VectorHash
    {
        std::size_t operator()(const std::vector<int>& v) const {
            std::size_t hash = 0;

            for (const int& element : v) {
                hash ^= std::hash<int>{}(element) + 0x9e3779b9 + (hash << 6) + (hash >> 2);
            }

            return hash;
        }
    };
    
    std::vector<std::vector<int>> pacificAtlantic(std::vector<std::vector<int>>& heights)
    {
        // time complexity: O(m * n)
        // space complexity: O(n + m)
        
        const int ROWS = heights.size() - 1;
        const int COLS = heights[0].size() - 1;

        std::unordered_set<std::vector<int>, VectorHash> pacificSet;
        std::unordered_set<std::vector<int>, VectorHash> atlanticSet;

        for (int c = 0; c <= COLS; c++)
        {
            dfs(heights, pacificSet, 0, c, heights[0][c]);
            dfs(heights, atlanticSet, ROWS, c, heights[ROWS][c]);
        }
        for (int r = 0; r <= ROWS; r++)
        {
            dfs(heights, pacificSet, r, 0, heights[r][0]);
            dfs(heights, atlanticSet, r, COLS, heights[r][COLS]);
        }

        std::vector<std::vector<int>> ans;
        for (const std::vector<int>& v : pacificSet)
        {
            if (atlanticSet.count(v) != 0)
            {
                ans.push_back(v);
            }
        }
        return ans;
    }

    void dfs(const std::vector<std::vector<int>>& heights, std::unordered_set<std::vector<int>, VectorHash>& set, int r, int c, int prevHeight)
    {
        if (r < 0 || r >= heights.size() || c < 0 || c >= heights[0].size() || set.find({r, c}) != set.end() || heights[r][c] < prevHeight)
        {
            return;
        }

        set.insert({r, c});

        dfs(heights, set, r + 1, c, heights[r][c]);
        dfs(heights, set, r - 1, c, heights[r][c]);
        dfs(heights, set, r, c + 1, heights[r][c]);
        dfs(heights, set, r, c - 1, heights[r][c]);
    }
};

int main()
{
    Solution s;
    std::vector<std::vector<int>> heights({{3,3,3,3,3,3},
                                           {3,0,3,3,0,3},
                                           {3,3,3,3,3,3}});
    s.pacificAtlantic(heights);
}