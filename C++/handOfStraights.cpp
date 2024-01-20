#include <vector>
#include <algorithm>
#include <unordered_map>

class Solution {
public:
    bool isNStraightHand(std::vector<int>& hand, int groupSize)
    {
        // time complexity: O(n log n)
        // space complexity: O(n)
        
        if (hand.size() % groupSize != 0)
        {
            return false;
        }

        std::sort(hand.begin(), hand.end());
        std::unordered_map<int, int> map;
        std::for_each(hand.begin(), hand.end(), [&map](int value) { map[value]++; });

        auto last = std::unique(hand.begin(), hand.end());
        hand.erase(last, hand.end());
        std::make_heap(hand.begin(), hand.end(), std::greater<int>());

        int cur;
        int curSize = 0;
        while (!hand.empty())
        {
            int first = hand[0];

            for (size_t i = 0; i < groupSize; i++)
            {
                if (map[first + i] <= 0)
                {
                    return false;
                }
                map[first + i]--;

                if (map[first + i] == 0)
                {
                    if (first + i != hand[0])
                    {
                        return false;
                    }
                    std::pop_heap(hand.begin(), hand.end(), std::greater<int>());
                    hand.pop_back();
                }
            }
        }
        return true;
    }

    bool isNStraightHandInPlace(std::vector<int>& hand, int groupSize)
    {
        // time complexity: O(n^2)
        // space complexity: O(1)
        
        if (hand.size() % groupSize != 0)
        {
            return false;
        }

        std::sort(hand.begin(), hand.end());
        int curSize = 0;
        int cur;

        while (!hand.empty())
        {
            if (curSize == 0)
            {
                cur = hand[0];
                hand.erase(hand.begin());
                curSize++;
                continue;
            }
            
            if (curSize == groupSize)
            {
                curSize = 0;
                continue;
            }

            auto it = std::lower_bound(hand.begin(), hand.end(), cur + 1);
            if (it != hand.end() && *it == cur + 1)
            {
                int index = std::distance(hand.begin(), it);
                cur++;
                curSize++;
                hand.erase(hand.begin() + index);
                continue;
            }
            return false;
        }
        return true;
    }
};
