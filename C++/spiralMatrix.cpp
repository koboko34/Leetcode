#include <vector>
#include <unordered_set>

class Solution {
public:
    std::vector<int> spiralOrder(std::vector<std::vector<int>>& matrix)
    {
        // time complexity: O(m * n)
        // space complexity: O(1)
        
        std::vector<int> ans;

        int left = 0;
        int right = matrix[0].size();
        int top = 0;
        int bot = matrix.size();

        while (left < right && top < bot)
        {
            for (size_t i = left; i < right; i++)
            {
                ans.push_back(matrix[top][i]);   
            }
            top++;

            for (size_t i = top; i < bot; i++)
            {
                ans.push_back(matrix[i][right - 1]);
            }
            right--;

            if (left >= right || top >= bot)
            {
                break;
            }

            for (int i = right - 1; i >= left; i--)
            {
                ans.push_back(matrix[bot - 1][i]);
            }
            bot--;

            if (left == right || top == bot)
            {
                return ans;
            }
            for (int i = bot - 1; i >= top; i--)
            {
                ans.push_back(matrix[i][left]);
            }
            left++;
        }
        return ans;
    }
};

int main()
{
    Solution s;
    s.spiralOrder(std::vector<std::vector<int>>{{1,2,3,4},{5,6,7,8},{9,10,11,12}});
}