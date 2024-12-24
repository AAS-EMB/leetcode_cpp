class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        const auto n = nums.size();
        vector<int> rotated(n, 0);

        // Update k with n
        k = k % n;

        // Fill rotated vector
        for (auto i = 0; i < n; ++i) {
            rotated[(i + k) % n] = nums[i];
        }

        // Move rotated to nums
        nums = move(rotated);
    }
};