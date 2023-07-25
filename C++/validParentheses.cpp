#include <string>
#include <stack>

class Solution {
public:
    bool isValid(std::string s)
    {       
        if (s.empty())
            return true;

        std::stack<char> stack;
        for (const char c : s)
        {
            if (c == '(' || c == '{' || c == '[')
            {
                stack.push(c);
                continue;
            }

            switch (c)
            {
            case ')':
                if (!stack.empty() && stack.top() == '(')
                {
                    stack.pop();
                    continue;
                }
                return false;
            case '}':
                if (!stack.empty() && stack.top() == '{')
                {
                    stack.pop();
                    continue;
                }
                return false;
            case ']':
                if (!stack.empty() && stack.top() == '[')
                {
                    stack.pop();
                    continue;
                }
                return false;
            default:
                return false;
            }
        }
        
        return stack.empty();
    }
};

int main()
{
    std::string one = "()";
    std::string two = "{}";
    std::string three = "[]";
    std::string four = "([])";
    std::string five = "([)]";

    Solution s;
    s.isValid(one);
    s.isValid(two);
    s.isValid(three);
    s.isValid(four);
    s.isValid(five);
}