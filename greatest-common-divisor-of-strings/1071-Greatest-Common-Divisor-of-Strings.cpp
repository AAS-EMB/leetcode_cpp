class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        string result;
        const auto size = min(str1.size(), str2.size());

        for (auto i = 0; i < size; ++i) {
            if (auto prefix = str2.substr(0, i + 1); is_prefix_ok(str1, prefix) and is_prefix_ok(str2, prefix)) {
                result = prefix;
            }
        }

        return result;
    }

    constexpr bool is_prefix_ok(auto const& s, auto const& prefix) {
        const auto prefix_size = prefix.size();

        for (auto i = 0; i < s.size(); i += prefix_size) {
            if (s.substr(i, prefix_size) not_eq prefix)
                return false;
        }

        return true;
    }
};