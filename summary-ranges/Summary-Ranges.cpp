class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        if (nums.size() == 0) {
            return {};
        }

        vector<string> out;
        auto a = nums[0], b = nums[0];

        for (auto i = 1; i < nums.size(); ++i) {
            if ((nums[i - 1] not_eq nums[i] - 1) and (a not_eq b)) {
                out.push_back(std::to_string(a) + \->\ + std::to_string(b));
                a = nums[i];
            } else if ((nums[i - 1] not_eq nums[i] - 1) and (a == b)) {
                out.push_back(std::to_string(a));
                a = nums[i];
            }
            b = nums[i];
        }

        if (a == b) {
            out.push_back(std::to_string(b));
        } else {
            out.push_back(std::to_string(a) + \->\ + std::to_string(b));
        }

        return out;
    }
};