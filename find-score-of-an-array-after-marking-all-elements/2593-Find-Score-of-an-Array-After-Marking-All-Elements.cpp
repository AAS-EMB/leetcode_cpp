class Solution {
public:
    long long findScore(vector<int>& nums) {
        auto n = nums.size();

        // Fill vector of pair value and original indexes
        vector<pair<int, int>> sorted(nums.size());
        for (auto i = 0; i < n; ++i)
        { sorted[i] = { nums[i], i }; }

        // Sort based on the values
        stable_sort(sorted.begin(), sorted.end());

        auto score = 0ll;

        // Iterate over the sorted vector
        for (auto i = 0; i < n; ++i) {
            auto num = sorted[i].first;
            auto idx = sorted[i].second;

            // Check marked numbers
            if (nums[idx] not_eq -1) {
                score += num;
                nums[idx] = -1;

                // Marked left neighboor
                if (idx not_eq 0)
                { nums[idx - 1] = -1; }

                // Marked right neighboor
                if (idx not_eq n - 1)
                { nums[idx + 1] = -1; }
            }
        }
        return score;
    }
};