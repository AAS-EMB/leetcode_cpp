class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> store;

        for (auto const& c : magazine) {
            ++store[c];
        }

        for (auto it = ransomNote.begin(); it not_eq ransomNote.end(); ++it) {
            const auto c = *it;

            if (store.count(c) == 0)
            { return false; }

            if (store[c] == 0)
            { return false; }

            --store[c];
        }

        return true;
    }
};