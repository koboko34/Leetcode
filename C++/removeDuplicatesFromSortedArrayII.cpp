#include <vector>

class Solution {
public:
    int removeDuplicates(std::vector<int>& nums)
    {
        // time complexity: O(n)
        // space complexity: O(1)
        
        if (nums.size() == 1)
        {
            return 1;
        }
        
        int len = 2;
        int l = 1;
        int r = 2;
        bool second = nums[0] == nums[1];

        while (r < nums.size())
        {
            if (nums[l] == nums[r])
            {
                if (second)
                {
                    r++;
                    continue;
                }
                
                second = true;
                len++;
                l++;
                nums[l] = nums[r];
                r++;
                continue;
            }
            
            second = false;
            l++;
            nums[l] = nums[r];
            len++;           
            r++;
        }
        return len;
    }
};

int main()
{
    Solution s;
    s.removeDuplicates(std::vector<int>{1,1,1,2,2,3});
}