class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        auto k = 0;
        remove_if(nums.begin(), nums.end(), [&val, &k](int a) {
            if (a == val) { return true; }
            ++k;
            return false;
        });
        return k;

    }
};