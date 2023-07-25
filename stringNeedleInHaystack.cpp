#include <string>
#include <cstring>

class Solution {
public:
    int strStr(std::string haystack, std::string needle)
    {
        const char* hay = haystack.c_str();
        const char* loc = strstr(hay, needle.c_str());
        if (!loc)
        {
            return -1;
        }
        
        return loc - hay;
    }
};

int main()
{
    Solution s;
    s.strStr("hello", "ll");
}