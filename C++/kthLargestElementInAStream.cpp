#include <vector>
#include <algorithm>

class KthLargest {
public:
    std::vector<int> heap;
    int k;
    
    KthLargest(int k, std::vector<int>& nums)
    {
        // time complexity: O(n log k)
        // space complexity: O(n)
        
        this->k = k;

        heap = nums;
        std::make_heap(heap.begin(), heap.end(), std::greater<int>());

        while (heap.size() > k)
        {
            std::pop_heap(heap.begin(), heap.end(), std::greater<int>());
            heap.pop_back();
        }
    }
    
    int add(int val)
    {
        heap.push_back(val);
        std::push_heap(heap.begin(), heap.end(), std::greater<int>());

        if (heap.size() > k)
        {
            std::pop_heap(heap.begin(), heap.end(), std::greater<int>());
            heap.pop_back();
        }

        return heap[0];
    }
};

int main()
{
    std::vector<int> nums = {4, 5, 8, 2};
    
    KthLargest k(3, nums);
    k.add(3);
    k.add(5);
    k.add(10);
    k.add(9);
    k.add(4);
}