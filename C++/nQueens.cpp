#include <vector>
#include <string>
#include <unordered_set>

class Solution {
public:    
    std::vector<std::vector<std::string>> solveNQueens(int n)
    {
        // time complexity: O(n!)
        // space complexity: O(n)
        
        std::vector<std::vector<std::string>> boards;
        std::vector<std::string> board(n, std::string(n, '.'));
        std::unordered_set<int> cols;
        std::unordered_set<int> posDia;
        std::unordered_set<int> negDia;

        for (size_t col = 0; col < n; col++)
        {
            dfs(boards, board, cols, posDia, negDia, std::pair<int, int>(0, col), 1);
        }
        return boards;
    }

    void dfs(std::vector<std::vector<std::string>>& boards, std::vector<std::string>& board, std::unordered_set<int>& cols,
    std::unordered_set<int>& posDia, std::unordered_set<int>& negDia, std::pair<int, int> next, int row)
    {
        if (row == board.size())
        {
            board[next.first][next.second] = 'Q';
            boards.push_back(board);
            board[next.first][next.second] = '.';
            return;
        }

        board[next.first][next.second] = 'Q';
        cols.insert(next.second);
        posDia.insert(next.first + next.second);
        negDia.insert(next.first - next.second);

        for (size_t i = 0; i < board.size(); i++)
        {
            if (cols.find(i) != cols.end() || posDia.find(row + i) != posDia.end() ||
            negDia.find(row - i) != negDia.end())
            {
                continue;
            }
            dfs(boards, board, cols, posDia, negDia, {row, i}, row + 1);
        }

        board[next.first][next.second] = '.';
        cols.erase(next.second);
        posDia.erase(next.first + next.second);
        negDia.erase(next.first - next.second);
    }
};

int main()
{
    Solution s;
    s.solveNQueens(4);
}