class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        auto pref_size = pref.size();
        auto result    = 0;

        for (auto const& word : words) {
            if (word.substr(0, pref_size) == pref)
                ++result;
        }

        return result;
    }
};