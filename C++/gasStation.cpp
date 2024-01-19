#include <vector>
#include <numeric>

class Solution {
public:
    int canCompleteCircuit(std::vector<int>& gas, std::vector<int>& cost)
    {
        // time complexity: O(n)
        // space complexity: O(1)
        
        int gasSum = std::accumulate(gas.begin(), gas.end(), 0);
        int costSum = std::accumulate(cost.begin(), cost.end(), 0);

        if (costSum > gasSum)
        {
            return -1;
        }

        int total = 0;
        int start = 0;
        for (int i = 0; i < gas.size(); i++)
        {
            total += gas[i] - cost[i];
            if (total < 0)
            {
                total = 0;
                start = i + 1;
                continue;
            }
        }
        
        return start;
    }
};

int main()
{
    Solution s;
    std::vector<int> gas {1,2,3,4,5};
    std::vector<int> cost {3,4,5,1,2};
    s.canCompleteCircuit(gas, cost);
}