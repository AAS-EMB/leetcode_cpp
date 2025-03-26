class Solution {
public:
    int findMin(vector<int>& nums) {
        return binarySearch(nums);
    }

private:
    int binarySearch(vector<int> &nums) {
        if(nums.size() == 1) return nums[0];

        if(nums.size() == 2) return nums[0] > nums[1] ? nums[1] : nums[0];

        int left = 0, right = nums.size() - 1;
        int rotation = 0;

        while (left <= right) {
            if (nums[0] <= nums[right]) {
                return (rotation == 0 and right not_eq left) ? nums[rotation] : nums[rotation + 1];
            } else {
                rotation = --right;
            }
        }

        return -1;
    }
};