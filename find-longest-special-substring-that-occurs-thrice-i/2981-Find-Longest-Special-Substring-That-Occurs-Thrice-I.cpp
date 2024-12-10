class Solution {
public:
    int maximumLength(string s) {
        unordered_map<string, int> um;
        int max_length = -1;

        // Find special substring
        for (auto i = 0; i < s.size(); ++i) {
            // get remainded size
            auto remainded_size = s.size() - i;
            for (auto j = 1; j <= remainded_size; ++j) {
                // Get substring
                auto sub = s.substr(i, j);
                
                // Check substring - special or not
                if(not is_special(sub)) break;

                // Save substring to map
                ++um[sub];

                // Check size substring and change max_length 
                if (um[sub] >= 3) {
                    max_length = max(max_length, static_cast<int>(sub.size()));
                }
            }
        }

        return max_length;
    }

private:
    // Validator special string
    bool is_special(string const& s) {
        for (auto i = 1; i < s.size(); ++i) {
            if (s[0] not_eq s[i])
                return false;
        }
        return true;
    }
};