#include <vector>

class Solution {
public:
    void gameOfLife(std::vector<std::vector<int>>& board)
    {
        // time complexity: O(m * n)
        // space complexity: O(m * n)
        
        std::vector<std::vector<int>> newBoard(board.size(), std::vector<int>(board[0].size(), 0));

        for (size_t i = 0; i < board.size(); i++)
        {
            for (size_t j = 0; j < board[0].size(); j++)
            {
                applyRules(board, newBoard, i, j);
            }
        }
        board = newBoard;
    }

    void applyRules(const std::vector<std::vector<int>>& board, std::vector<std::vector<int>>& newBoard, int i, int j)
    {
        int colLen = board.size();
        int rowLen = board[0].size();
        int curTotalIndex = i * rowLen + j;
        
        int liveNeighbours = 0;
        int totalIndex = curTotalIndex - rowLen - 1;
        int row = totalIndex / rowLen;
        int col = totalIndex % rowLen;
        if (j > 0 && totalIndex >= 0)
        {
            if (board[row][col] == 1)
            {
                liveNeighbours++;
            }
        }

        totalIndex = curTotalIndex + rowLen - 1;
        if (j > 0 && totalIndex < rowLen * colLen)
        {
            row = totalIndex / rowLen;
            col = totalIndex % rowLen;
            if (board[row][col] == 1)
            {
                liveNeighbours++;
            }
        }

        totalIndex = curTotalIndex - rowLen;
        if (totalIndex >= 0)
        {
            row = totalIndex / rowLen;
            col = totalIndex % rowLen;
            if (board[row][col] == 1)
            {
                liveNeighbours++;
            }
        }

        totalIndex = curTotalIndex + rowLen;
        if (totalIndex < rowLen * colLen)
        {
            row = totalIndex / rowLen;
            col = totalIndex % rowLen;
            if (board[row][col] == 1)
            {
                liveNeighbours++;
            }
        }

        totalIndex = curTotalIndex - rowLen + 1;
        row = totalIndex / rowLen;
        col = totalIndex % rowLen;
        if (j < rowLen - 1 && totalIndex >= 0)
        {
            if (board[row][col] == 1)
            {
                liveNeighbours++;
            }
        }

        totalIndex = curTotalIndex + rowLen + 1;
        if (j < rowLen - 1 && totalIndex < rowLen * colLen)
        {
            row = totalIndex / rowLen;
            col = totalIndex % rowLen;
            if (board[row][col] == 1)
            {
                liveNeighbours++;
            }
        }

        totalIndex = curTotalIndex - 1;
        if (j > 0 && totalIndex < rowLen * colLen)
        {
            row = totalIndex / rowLen;
            col = totalIndex % rowLen;
            if (board[row][col] == 1)
            {
                liveNeighbours++;
            }
        }

        totalIndex = curTotalIndex + 1;
        if (j < rowLen - 1 && totalIndex < rowLen * colLen)
        {
            row = totalIndex / rowLen;
            col = totalIndex % rowLen;
            if (board[row][col] == 1)
            {
                liveNeighbours++;
            }
        }

        if (board[i][j] == 0)
        {
            if (liveNeighbours == 3)
            {
                newBoard[i][j] = 1;
            }
        }
        else if (liveNeighbours >= 2 && liveNeighbours <= 3)
        {
            newBoard[i][j] = 1;
        }   
    }
};

int main()
{
    Solution s;
    std::vector<std::vector<int>> grid {{0,1,0},{0,0,1},{1,1,1},{0,0,0}};
    s.gameOfLife(grid);
}