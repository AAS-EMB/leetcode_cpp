class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        auto prev_1 = numeric_limits<int>::min();

        for (auto i = 0; i < nums.size(); ++i)
        {
            if (nums[i] == 1)
            {
                if (static_cast<long long>(i) - prev_1 <= k)
                {
                    return false;
                }
                prev_1 = i;
            }
        }

        return true;
    }
};