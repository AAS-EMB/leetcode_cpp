class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        const auto n = words.size();
        auto result  = 0;

        for (auto i = 0; i < n; ++i) {
            for (auto j = i + 1; j < n; ++j) {
                if (not isPrefixAndSuffix(words[i], words[j])) { continue; }

                ++result;
            }
        }

        return result;
    }

private:
    bool isPrefixAndSuffix(string str1, string str2) {
        // check size
        if (str1.size() > str2.size()) { return false; } 
        // check prefix
        if (str2.substr(0, str1.size()) not_eq str1) { return false; }
        // check suffix
        if (str2.substr(str2.size() - str1.size(), str2.size()) not_eq str1) { return false; }

        return true;
    }
};