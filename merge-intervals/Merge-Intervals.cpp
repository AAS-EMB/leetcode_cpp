class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> result;

        // Sort intervals
        sort(intervals.begin(), intervals.end());

        // Iterating
        for (auto & interval : intervals)
        {
            // Check overlapping
            auto isOverlap = [&interval, &result]()
            {
                auto end_prev_i  = result.back()[1];
                auto start_cur_i = interval[0];

                return end_prev_i >= start_cur_i;
            };

            // Push intervals
            if (result.empty() or (not isOverlap()))
            {
                result.push_back(interval);
            }
            else
            {
                if (result.back()[1] < interval[1])
                {
                    result.back()[1] = interval[1];
                }
            }
        }

        return result;
    }
};