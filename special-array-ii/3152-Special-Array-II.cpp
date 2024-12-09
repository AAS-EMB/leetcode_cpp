class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> summary(nums.size(), 0);

        auto counter = 0;
        for (auto i = 1; i < summary.size(); ++i) {
            if (nums[i - 1] % 2 not_eq nums[i] % 2) {
                ++counter;
            }
            summary[i] = counter;
        }

        vector<bool> out(queries.size(), false);

        for (auto i = 0; i < out.size(); ++i) {
            if (summary[queries[i][1]] - summary[queries[i][0]] == queries[i][1] - queries[i][0]) {
                out[i] = true;
            }
        }

        return out;
    }
};