#include <vector>

class Solution {
public:
    void nextPermutation(std::vector<int>& nums)
    {
        // time complexity: O(n)
        // space complexity: O(1)
        
        int pivot = nums.size() - 1;

        for (int i = nums.size() - 1; i >= 0; i--)
        {
            if (nums[i] < nums[pivot])
            {
                break;
            }
            pivot = i;
        }
        
        pivot--;
        if (pivot < 0)
        {
            std::reverse(nums.begin(), nums.end());
            return;
        }
        
        // swap pivot with next
        // find index of next
        int nextIndex = findIndex(nums, pivot + 1, nums.size() - 1, nums[pivot]);
        
        int pivotVal = nums[pivot];
        nums[pivot] = nums[nextIndex];
        nums.erase(nums.begin() + nextIndex);

        // insert pivotVal in correct place within the reversed tail
        insertToVector(nums, pivot + 1, nums.size() - 1, pivotVal);

        // reverse the decreasing tail
        std::reverse(nums.begin() + pivot + 1, nums.end());
    }

    int findIndex(std::vector<int>& nums, int start, int end, int target)
    {
        int mid;
        int index = -1;
        while (start <= end)
        {
            mid = (start + end) / 2;

            if (nums[mid] > target)
            {
                if (index < 0 || nums[mid] < nums[index])
                {
                    index = mid;
                }
                start = mid + 1;
            }
            else
            {
                end = mid - 1;
            }
        }
        return index;
    }

    void insertToVector(std::vector<int>& nums, int start, int end, int val)
    {
        int mid;
        while (start < end)
        {
            mid = (start + end) / 2;

            if (nums[mid] == val)
            {
                nums.insert(nums.begin() + mid, val);
                return;
            }
            else if (nums[mid] < val)
            {
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
        }

        if (nums.size() <= start)
        {
            nums.push_back(val);
            return;
        }
        
        if (nums[start] < val)
        {
            nums.insert(nums.begin() + start, val);
        }
        else
        {
            nums.insert(nums.begin() + start + 1, val);
        }
    }
};

int main()
{
    Solution s;
    s.nextPermutation(std::vector<int>{1, 1, 5});
}