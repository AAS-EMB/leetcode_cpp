class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        return target_sum({ nums.begin(), nums.end() }, target, 0);
    }

    int target_sum(span<int> s, int target, int result) {
        if (s.empty()) {
            return target == result ? 1 : 0;
        }

        auto count = 0;

        count += target_sum({ next(s.begin()), s.end() }, target, result - s[0]);
        count += target_sum({ next(s.begin()), s.end() }, target, result + s[0]);

        return count;
    }
};