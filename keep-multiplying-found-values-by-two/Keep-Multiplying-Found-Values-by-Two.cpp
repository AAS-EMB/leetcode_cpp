class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        while (true)
        {
            if (auto it = find(nums.begin(), nums.end(), original); it == nums.end())
            {
                break;
            }
            original *= 2;
        }
        return original;
    }
};