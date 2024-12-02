#include <unordered_map>

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        using namespace std;

        unordered_map<int, int> um;

        for (auto i = 0; i < nums.size(); ++i) {
            int diff = target - nums[i];

            if (um.count(diff)) {
                return { um[diff], i };
            }

            um[nums[i]] = i;
        }
        return {};
    }
};