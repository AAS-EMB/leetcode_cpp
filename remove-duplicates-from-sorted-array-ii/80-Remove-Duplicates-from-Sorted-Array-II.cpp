class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        const auto n = nums.size();

        if (n <= 2) return n;

        auto j = 2;
        for (auto i = 2; i < n; ++i) {
            if (nums[i] not_eq nums[j - 2]) {
                nums[j] = nums[i];
                ++j;
            }
        }

        return j;
    }
};