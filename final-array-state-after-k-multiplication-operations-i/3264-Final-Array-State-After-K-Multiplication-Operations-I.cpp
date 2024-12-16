class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        for (auto i = 0; i < k; ++i) {
            if (auto it = min_element(nums.begin(), nums.end()); it not_eq nums.end()) {
                *it = *it * multiplier;
            }
        }

        return nums;
    }
};