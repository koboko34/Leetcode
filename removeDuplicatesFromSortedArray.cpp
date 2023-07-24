#include <vector>

class Solution {
public:
    int removeDuplicates(std::vector<int>& nums)
    {
        if (nums.size() < 2)
            return nums.size();
        
        int j = 1;
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] != nums[i - 1])
            {
                nums[j] = nums[i];
                j++;
            }
        }
        return j;
    }
};

int main()
{    
    std::vector<int> v;
    v.push_back(1);
    v.push_back(2);
    
    Solution s;
    s.removeDuplicates(v);
}