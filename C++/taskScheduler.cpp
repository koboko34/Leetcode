#include <vector>
#include <queue>

class Solution {
public:
    int leastInterval(std::vector<char>& tasks, int n)
    {
        // time complexity: O(n * m)
        // space complexity: O(n)
        
        int freq[26] {};
        for (char c : tasks)
        {
            freq[c - 'A']++;
        }

        std::priority_queue<int> pq;
        for (int i : freq)
        {
            if (i != 0)
            {
                pq.push(i);
            }
        }

        std::queue<std::pair<int, int>> queue;
        int time = 0;
        while (!pq.empty() || !queue.empty())
        {
            if (!queue.empty() && queue.front().second <= time)
            {
                pq.push(queue.front().first);
                queue.pop();
            }
            
            time++;
            if (!pq.empty())
            {
                int i = pq.top() - 1;
                pq.pop();

                if (i > 0)
                {
                    queue.push(std::pair<int, int>(i, time + n));
                }
            }
        }
        return time;
    }
};

int main()
{
    Solution s;
    std::vector<char> tasks {'A', 'A', 'A', 'B', 'B', 'B', };
    s.leastInterval(tasks, 2);
}