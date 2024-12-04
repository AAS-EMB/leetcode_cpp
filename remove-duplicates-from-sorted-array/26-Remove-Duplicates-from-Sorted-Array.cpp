class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        auto wr_index = 1;
        auto current  = nums[0];

        for (auto i = 1; i < nums.size(); ++i) {
            if (current ^ nums[i]) {
                current = nums[i];
                nums[wr_index++] = current;
            }
        }

        return wr_index;
    }
};