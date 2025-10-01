class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result = 0;

        for (auto const& n : nums)
        {
            result ^= n;
        }

        return result;
    }
};