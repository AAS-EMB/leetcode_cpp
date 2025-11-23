class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        auto result = 0;

        for (auto const& num : nums)
        {
            result += (num % 3 not_eq 0);
        }

        return result;
    }
};