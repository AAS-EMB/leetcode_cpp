class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> um;

        for (auto const& item : nums)
        { ++um[item]; }

        for (auto const& [key, value] : um) {
            if (value > nums.size() / 2) {
                return key;
            }
        }
        return 0;
    }
};