class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        std::unordered_map<int, int> map;

        for (auto i = 0; i < nums.size(); ++i) {
            if (map.count(nums[i])) {
                auto j = map[nums[i]];
                if (std::abs(j - i) <= k) {
                    return true;
                }
            }
            map[nums[i]] = i;
        }

        return false;
    }
};