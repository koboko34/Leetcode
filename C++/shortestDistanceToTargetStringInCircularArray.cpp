#include <vector>
#include <string>

class Solution {
public:
    int closetTarget(std::vector<std::string>& words, std::string target, int startIndex)
    {
        // time complexity: O(n)
        // space complexity: O(1)
        
        for (int i = 0; i < words.size() / 2 + 1; i++)
        {
            int index = (startIndex + i) % words.size();
            if (words[index] == target)
            {
                return i;
            }
            
            index = (startIndex - i);
            if (index < 0)
            {
                index = words.size() + index;
            }
            else
            {
                index = index % words.size();
            }

            if (words[index] == target)
            {
                return i;
            }
        }
        return -1;
    }
};

int main()
{
    Solution s;
    s.closetTarget(std::vector<std::string>{"a", "b,", "leetcode"}, "leetcode", 0);
}