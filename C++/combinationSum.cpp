#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> combinationSum(std::vector<int>& candidates, int target)
    {
        // time complexity: O(n ^ max depth)
        // space complexity: O(n)
        
        std::vector<std::vector<int>> combos;
        std::vector<int> combo;

        dfs(combos, combo, candidates, target, 0, 0);

        return combos;  
    }

    void dfs(std::vector<std::vector<int>>& combos, std::vector<int>& combo, const std::vector<int>& candidates, int target, int index, int total)
    {
        if (total > target || index >= candidates.size())
        {
            return;
        }

        if (total == target)
        {
            combos.push_back(combo);
            return;
        }

        combo.push_back(candidates[index]);
        dfs(combos, combo, candidates, target, index, total + candidates[index]);
        combo.pop_back();
        dfs(combos, combo, candidates, target, index + 1, total);
    }
};
