class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        auto max_length = 0;
        unordered_set<char> us;

        for (auto i = 0, j = 0; i < s.size(); ++i) {
            while (us.count(s[i])) {
                us.erase(s[j]);
                ++j;
            }

            us.insert(s[i]);
            max_length = std::max(max_length, static_cast<int>(us.size()));
        }

        return max_length;
    }
};