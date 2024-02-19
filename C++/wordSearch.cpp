#include <vector>
#include <string>
#include <unordered_set>

class Solution {
public:
    struct pair_hash
    {
        template <class T1, class T2>
        std::size_t operator () (const std::pair<T1, T2>& p) const
        {
            auto hash1 = std::hash<T1>{}(p.first);
            auto hash2 = std::hash<T2>{}(p.second);

            return hash1 ^ hash2; 
        }
    };
    
    bool exist(std::vector<std::vector<char>>& board, std::string word)
    {
        // time complexity: O(n * m * 4^w) where w is the length of the word
        // space complexity: O(n)
        
        std::unordered_set<std::pair<int, int>, pair_hash> visited;
        for (size_t i = 0; i < board.size(); i++)
        {
            for (size_t j = 0; j < board[0].size(); j++)
            {
                if (search(board, word, visited, i, j, 0))
                {
                    return true;
                }
                visited.clear();
            }
        }
        return false;
    }

    bool search(const std::vector<std::vector<char>>& board, const std::string& word, std::unordered_set<std::pair<int, int>, pair_hash>& visited,
                int row, int col, int charIndex)
    {
        if (charIndex == word.size())
        {
            return true;
        }
        if (row < 0 || row >= board.size() || col < 0 || col >= board[0].size() ||
            visited.find(std::pair<int, int>(row, col)) != visited.end() || board[row][col] != word[charIndex])
        {
            return false;
        }

        visited.insert({row, col});
        if (search(board, word, visited, row + 1, col, charIndex + 1) ||
            search(board, word, visited, row - 1, col, charIndex + 1) ||
            search(board, word, visited, row, col + 1, charIndex + 1) ||
            search(board, word, visited, row, col - 1, charIndex + 1))
        {
            return true;
        }
        visited.erase({row, col});
        return false;
    }
};

int main()
{
    Solution s;
    std::vector<std::vector<char>> board{{'A','B','C','E'},{'S','F','E','S'},{'A','D','E','E'}};
    s.exist(board, "ABCESEEEFS");
}