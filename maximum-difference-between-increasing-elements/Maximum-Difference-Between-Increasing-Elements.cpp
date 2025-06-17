class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        auto result = -1;
        auto minv = nums[0];
        for (auto i = 1; i < nums.size(); ++i) {
            (nums[i] > minv) ? (result = max(result, nums[i] - minv))
                             : (minv = nums[i]);
        }
        return result;
    }
};