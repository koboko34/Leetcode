#include <vector>
#include <algorithm>
#include <map>
#include <deque>

class Solution {
public:
    std::vector<int> maxSlidingWindow(std::vector<int>& nums, int k)
    {
        // time complexity: O(n)
        // space complexity: O(n)
        
        std::deque<int> queue;
        std::vector<int> ans;
        int l = 0;
        int r = 0;

        while (r < nums.size())
        {
            while (!queue.empty() && nums[queue.front()] < nums[r])
            {
                queue.pop_front();
            }
            queue.push_front(r);

            if (queue.back() < l)
            {
                queue.pop_back();
            }

            if (r + 1 >= k)
            {
                ans.push_back(nums[queue.back()]);
                l++;
            }
            r++;
        }
        return ans;
    }
    
    std::vector<int> maxSlidingWindowMap(std::vector<int>& nums, int k)
    {
        // time complexity: O(n)
        // time complexity: O(n)
        
        std::map<int, int> map;
        for (int i = 0; i < k - 1; i++)
        {
            map[nums[i]]++;
        }
        
        std::vector<int> ans;
        int l = 0;
        int r = k;
        while (r <= nums.size())
        {
            map[nums[r - 1]]++;
            auto max = --map.end();
            ans.push_back(max->first);

            if (map[nums[l]] == 1)
            {
                map.erase(nums[l]);
            }
            else
            {
                map[nums[l]]--;
            }            

            l++;
            r++;
        }
        return ans;
    }
    
    std::vector<int> maxSlidingWindowHeap(std::vector<int>& nums, int k)
    {
        // time complexity: O(n^2)
        // space complexity: O(n)
        
        std::vector<int> ans;
        std::vector<int> window(nums.begin(), nums.begin() + k - 1);

        int l = 0;
        int r = k;
        while (r <= nums.size())
        {
            window.push_back(nums[r - 1]);
            std::make_heap(window.begin(), window.end());
            ans.push_back(window[0]);

            auto index = std::find(window.begin(), window.end(), nums[l]);
            window.erase(index);
            l++;
            r++;
        }
        return ans;
    }
};

int main()
{
    Solution s;
    s.maxSlidingWindow(std::vector<int>{7, 2, 4}, 2);
}