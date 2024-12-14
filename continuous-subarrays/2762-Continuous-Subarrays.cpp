class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        // Variables
        auto left      = 0;
        auto right     = 0;
        auto count     = 0ll;

        // Multiset for saved current window
        multiset<int> s;

        // Condition
        while (right not_eq nums.size()) {
            // Insert element
            s.insert(nums[right]);

            // Shrink window from left
            while (left < right and *prev(s.end()) - *s.begin() > 2) {
                auto it = s.find(nums[left++]);
                s.erase(it);
            }

            // Add count of all valid subarrays ending at right
            count += right - left + 1ll;
            ++right;
        }

        return count;
    }
};