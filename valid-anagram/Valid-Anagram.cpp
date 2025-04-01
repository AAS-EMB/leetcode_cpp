class Solution {
public:
    bool isAnagram(string s, string t) {
        std::unordered_map<char, int> store;

        // Store and count characters from s
        for (auto const& c : s)
        { ++store[c]; }

        // Decrement characters from t
        for (auto const& c : t)
        { --store[c]; }

        // Check value from map
        for (auto const& [key, value] : store) {
            if (value) {
                return false;
            }
        }

        return true;
    }
};