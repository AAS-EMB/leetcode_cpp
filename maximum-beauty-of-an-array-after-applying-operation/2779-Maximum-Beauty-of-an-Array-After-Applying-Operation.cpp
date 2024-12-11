class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        // Sorting array
        stable_sort(nums.begin(), nums.end());

        auto result = 0l;

        for (auto i = 0; i < nums.size(); ++i) {

            // Find upper bound iterator with maximum possible equal value 
            auto it = upper_bound(nums.begin() + i, nums.end(), nums[i] + 2 * k);

            // Update result
            result = max(result, abs(distance(nums.begin() + i, it)));
        }

        return result;

    }
};