class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        vector<int> nums;

        sort(intervals.begin(), intervals.end(), [](auto lhs, auto rhs) {
            return (lhs[1] < rhs[1]) or (lhs[1] == rhs[1] and lhs[0] > rhs[0]);
        });

        for (auto const& interval : intervals)
        {
            auto start = interval[0];
            auto end   = interval[1];
            auto count = 0;

            for (auto const& num : nums)
            {
                if (num >= start and num <= end)
                {
                    count++;
                }
                if (count >= 2) break;
            }

            if (count == 0)
            {
                nums.push_back(interval[1] - 1);
                nums.push_back(interval[1]);
            }
            else if (count == 1)
            {
                nums.push_back(interval[1]);
            }
        }

        return nums.size();
    }
};