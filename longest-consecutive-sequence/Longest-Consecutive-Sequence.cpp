class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        std::unordered_set<int> s( nums.begin(), nums.end() );
        auto result = 0;

        for (auto const& num : s) {
            if (s.find(num - 1) == s.end()) {
                auto len = 1;

                while (s.count(num + len) > 0) {
                    ++len;
                }

                result = std::max(result, len);
            }
        }
        
        return result;
    }
};