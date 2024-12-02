#include <stack>

class Solution {
public:
    bool isValid(string s) {
        using namespace std;

        if (s.size() == 0)
        { return true; }

        if (s.size() == 1)
        { return false; }

        stack<char> my_stack;

        for (auto i = 0; i < s.size(); ++i) {
            char c = s[i];
            if(c == '}' or c == ']' or c == ')') {
                if(my_stack.size() == 0)
                { return false; }

                if(c == '}' and my_stack.top() not_eq '{') return false;
                if(c == ']' and my_stack.top() not_eq '[') return false;
                if(c == ')' and my_stack.top() not_eq '(') return false;

                my_stack.pop();
            } else {
                my_stack.push(c);
            }
        }
        return my_stack.size() == 0 ? true : false;
    }
};
