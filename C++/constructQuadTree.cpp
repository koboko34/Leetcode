#include <vector>

// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};

class Solution {
public:
    Node* construct(std::vector<std::vector<int>>& grid)
    {
        // time complexity: O(n^2 log n)
        // space complexity: O(n)
        
        Node* root = dfs(grid, grid.size(), 0, 0);
        return root;
    }

    Node* dfs(const std::vector<std::vector<int>>& grid, int n, int row, int col)
    {
        bool same = true;

        for (size_t i = 0; i < n; i++)
        {
            for (size_t j = 0; j < n; j++)
            {
                if (grid[row][col] != grid[row + i][col + j])
                {
                    same = false;
                    break;
                }
            }

            if (!same)
            {
                break;
            }
        }
        
        if (same)
        {
            return new Node(grid[row][col], true);
        }
        
        n /= 2;
        Node* topLeft = dfs(grid, n, row, col);
        Node* topRight = dfs(grid, n, row, col + n);
        Node* bottomLeft = dfs(grid, n, row + n, col);
        Node* bottomRight = dfs(grid, n, row + n, col + n);
        return new Node(1, false, topLeft, topRight, bottomLeft, bottomRight);
    }
};

int main()
{
    Solution s;
    std::vector<std::vector<int>> grid{{0, 1}, {1, 0}};
    s.construct(grid);
}