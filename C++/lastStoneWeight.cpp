#include <queue>

class Solution {
public:
    int lastStoneWeight(std::vector<int>& stones)
    {
        // time complexity: O(n log n)
        // space complexity: O(n)
        
        std::priority_queue<int> pq(stones.begin(), stones.end());
        int first;
        int second;

        while (pq.size() > 1)
        {
            first = pq.top();
            pq.pop();
            second = pq.top();
            pq.pop();

            if (first == second)
            {
                continue;
            }

            first -= second;
            pq.push(first);
        }

        if (pq.empty())
        {
            return 0;
        }

        return pq.top();
    }
};