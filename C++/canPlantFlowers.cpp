#include <vector>

class Solution {
public:
    bool canPlaceFlowers(std::vector<int>& flowerbed, int n)
    {        
        // time complexity: O(n)
        // space complexity: O(n)
        
        flowerbed.insert(flowerbed.begin(), 0);
        flowerbed.push_back(0);
        
        for (size_t i = 1; i < flowerbed.size() - 1; i++)
        {
            if (flowerbed[i - 1] == 0 && flowerbed[i] == 0 && flowerbed[i + 1] == 0)
            {
                i++;
                n--;
                if (n <= 0)
                {
                    return true;
                }
            }
        }
        return n <= 0;
    }
};

int main()
{
    Solution s;
    s.canPlaceFlowers(std::vector<int>{0,0,0,0}, 3);
}