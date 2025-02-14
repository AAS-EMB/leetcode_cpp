class Solution {
public:
    bool isSubsequence(string s, string t) {
        auto s_index = 0;
        auto t_index = 0;

        while (t_index not_eq t.size()) {

            if (s[s_index] == t[t_index]) { ++s_index; }
            ++t_index;

        }

        return s_index == s.size();
    }
};