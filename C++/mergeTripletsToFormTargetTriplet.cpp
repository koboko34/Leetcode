#include <vector>
#include <unordered_set>

class Solution {
public:
    bool mergeTriplets(std::vector<std::vector<int>>& triplets, std::vector<int>& target)
    {        
        // time complexity: O(n)
        // space complexity: O(1)
        
        std::unordered_set<int> ans;
        for (const std::vector<int>& t : triplets)
        {
            if (t[0] > target[0] || t[1] > target[1] || t[2] > target[2])
            {
                continue;
            }
            
            for (int i = 0; i < 3; i++)
            {
                if (t[i] == target[i])
                {
                    ans.insert(i);
                } 
            }
        }
        return ans.size() == 3;    
    }
};