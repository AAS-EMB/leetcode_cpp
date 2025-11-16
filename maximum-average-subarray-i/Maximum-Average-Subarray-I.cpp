class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double curr_sum = accumulate(nums.begin(), nums.begin() + k, 0);
        double max_sum = curr_sum;

        for (auto i = k; i < nums.size(); ++i)
        {
            curr_sum += nums[i] - nums[i - k];
            max_sum = max(max_sum, curr_sum);
        }

        return max_sum / k;
    }
};