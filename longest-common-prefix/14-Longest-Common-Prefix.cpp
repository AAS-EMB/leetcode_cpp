class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        using namespace std;

        if (strs.empty()) { return \\s; }

        auto prefix = strs[0];
        auto prefix_length = prefix.length();

        for (auto i = 1; i < strs.size(); ++i) {
            auto str = strs[i];
            while (prefix_length > prefix.size() or prefix not_eq str.substr(0, prefix_length)) {
                --prefix_length;
                if (prefix_length == 0) { return \\s; }
                prefix = prefix.substr(0, prefix_length);
            }
        }
        
        return prefix;
    }
};