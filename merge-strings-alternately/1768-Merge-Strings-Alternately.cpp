class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string result;
        const auto size = max(word1.size(), word2.size());

        for (auto i = 0; i < size; ++i) {
            if (i < word1.size()) {
                result += word1[i];
            }
            if (i < word2.size()) {
                result += word2[i];
            }
        }

        return result;
    }
};