class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;

        unordered_map<string, vector<string>> map;
        for (auto const& str : strs) {
            auto word = str;
            sort(word.begin(), word.end());
            map[word].push_back(str);
        }

        for (auto const& [_, value] : map) {
            result.push_back(move(value));
        }

        return result;
    }
};