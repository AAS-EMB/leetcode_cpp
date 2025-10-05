class Solution {
public:
    bool isValid(string s) {
        std::stack<char> st;

        for (auto const& c : s)
        {
            if (c == '(' or c == '{' or c == '[')
            {
                st.push(c);
            }
            else
            {
                if (st.empty())
                {
                    return false;
                }

                auto top = st.top();
                st.pop();
                if (c == ')' and top not_eq '(') return false;
                if (c == ']' and top not_eq '[') return false;
                if (c == '}' and top not_eq '{') return false;
            }
        }

        return st.empty();
    }
};