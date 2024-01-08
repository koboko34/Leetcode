#include <queue>
#include <vector>

class Solution {
public:
    int findKthLargest(std::vector<int>& nums, int k)
    {
        // time complexity: O(n + k log n)
        // space complexity: O(n)
        
        std::priority_queue<int> heap(nums.begin(), nums.end());

        while (k > 1)
        {
            heap.pop();
            k--;
        }
        return heap.top();
    }

    int findKthLargestQuickSelect(std::vector<int>& nums, int k)
    {
        // time complexity: O(n) average, O(n^2) worst
        // space complexity: O(n)
        
        k = nums.size() - k;

        return quickSelect(nums, k, 0, nums.size() - 1);
    }

    int quickSelect(std::vector<int>& nums, int k, int l, int r)
    {
        int pivot = nums[r];
        int p = l;

        for (int i = l; i < r; i++)
        {
            if (nums[i] <= pivot)
            {
                int temp = nums[p];
                nums[p] = nums[i];
                nums[i] = temp;
                p++;
            }
        }
        nums[r] = nums[p];
        nums[p] = pivot;

        if (p > k)
        {
            return quickSelect(nums, k, l, p - 1);
        }
        else if (p < k)
        {
            return quickSelect(nums, k, p + 1, r);
        }
        return nums[k];
    }
};