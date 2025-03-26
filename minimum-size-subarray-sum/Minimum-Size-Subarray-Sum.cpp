class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        auto left = 0, right = 0;
        auto sum = 0;
        auto result = std::numeric_limits<int>::max();

        while (right not_eq nums.size()) {
            sum += nums[right];

            while (sum >= target) {
                result = std::min(result, right - left + 1);
                sum -= nums[left];
                ++left;
            }
            ++right;
        }

        return (result == std::numeric_limits<int>::max()) ? 0 : result;
    }

};