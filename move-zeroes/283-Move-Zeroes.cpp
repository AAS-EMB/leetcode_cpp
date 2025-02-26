class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        for (auto current = 0, last_zero = 0; current < nums.size(); ++current) {
            if (nums[current] not_eq 0) {
                swap(nums[last_zero++], nums[current]);
            }
        }
    }
};