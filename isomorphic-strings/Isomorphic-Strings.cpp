class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, int> char_ss;
        unordered_map<char, int> char_ts;

        for (auto i = 0; i < s.size(); ++i) {
            if (char_ss.count(s[i]) == 0) {
                char_ss[s[i]] = i;
            }

            if (char_ts.count(t[i]) == 0) {
                char_ts[t[i]] = i;
            }

            if (char_ss[s[i]] not_eq char_ts[t[i]]) {
                return false;
            }
        }

        return true;
    }
};