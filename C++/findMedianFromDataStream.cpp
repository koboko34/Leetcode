#include <vector>
#include <algorithm>

class MedianFinder {
public:
    std::vector<int> left;
    std::vector<int> right;

    MedianFinder()
    {
        
    }
    
    void addNum(int num)
    {
        // time complexity: O(log n)
        // space complexity: O(1)
        
        if (left.size() == 0)
        {
            left.push_back(num);
            return;
        }
        else if (right.size() == 0)
        {
            if (num >= left[0])
            {
                right.push_back(num);
            }
            else
            {
                right.push_back(left[0]);
                left[0] = num;
            }            
            return;
        }
        
        if (num <= left[0])
        {
            left.push_back(num);
            std::push_heap(left.begin(), left.end());

            if (left.size() - right.size() > 1)
            {
                int top = left[0];
                std::pop_heap(left.begin(), left.end());
                left.pop_back();

                right.push_back(top);
                std::push_heap(right.begin(), right.end(), std::greater<int>());
            }
        }
        else
        {
            right.push_back(num);
            std::push_heap(right.begin(), right.end(), std::greater<int>());

            if (right.size() - left.size() > 1)
            {
                int top = right[0];
                std::pop_heap(right.begin(), right.end(), std::greater<int>());
                right.pop_back();

                left.push_back(top);
                std::push_heap(left.begin(), left.end());
            }
        }
    }
    
    double findMedian()
    {
        if (left.size() == right.size())
        {
            return (double)(left[0] + right[0]) / 2.f;
        }
        else if (left.size() > right.size())
        {
            return left[0];
        }
        else
        {
            return right[0];
        }
    }
};