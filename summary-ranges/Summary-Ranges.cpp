class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        if (nums.empty())
        {
            return {};
        }

        vector<string> result;
        int left = 0, right = 1;

        while (right < nums.size())
        {
            if ((nums[right - 1] not_eq nums[right] - 1))
            {
                if (nums[left] not_eq nums[right - 1])
                {
                    result.push_back(to_string(nums[left]) + "->" + to_string(nums[right - 1]));
                }
                else
                {
                    result.push_back(to_string(nums[left]));
                }
                
                left = right;
            }

            ++right;
        }

        if (nums[left] not_eq nums[right - 1])
        {
            result.push_back(to_string(nums[left]) + "->" + to_string(nums[right - 1]));
        }
        else
        {
            result.push_back(to_string(nums[left]));
        }

        return result;
    }
};