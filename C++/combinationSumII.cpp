#include <vector>
#include <unordered_set>
#include <algorithm>

class Solution {
public:
    std::vector<std::vector<int>> combinationSum2(std::vector<int>& candidates, int target)
    {
        // time complexity: O(2^n)
        // space complexity: O(n)
        
        std::sort(candidates.begin(), candidates.end());
        std::vector<std::vector<int>> combos;
        std::vector<int> combo;
        dfs(combos, combo, candidates, 0, target, 0);

        return combos;
    }

    void dfs(std::vector<std::vector<int>>& combos, std::vector<int>& combo, const std::vector<int>& candidates, int index, int target, int total)
    {
        if (total > target)
        {
            return;
        }

        if (total == target)
        {
            combos.push_back(combo);
            return;
        }

        if (index >= candidates.size())
        {
            return;
        }
        
        combo.push_back(candidates[index]);
        dfs(combos, combo, candidates, index + 1, target, total + candidates[index]);
        combo.pop_back();

        int nextIndex = index + 1;
        while (nextIndex < candidates.size() && candidates[index] == candidates[nextIndex])
        {
            nextIndex++;
        }
        if (nextIndex < candidates.size())
        {
            dfs(combos, combo, candidates, nextIndex, target, total);
        }
    }
};

int main()
{
    Solution s;
    s.combinationSum2(std::vector<int>{10,1,2,7,6,1,5}, 8);
}