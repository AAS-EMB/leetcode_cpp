class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        // Sorting for binary search
        stable_sort(events.begin(), events.end(), [](auto const& v1, auto const& v2) {
            return v1[0] < v2[0];
        });

        // Make vector for max_values intervals
        vector<int> store_max(events.size(), 0);

        // Filling max score
        store_max.back() = events.back().at(2);
        for (int i = store_max.size() - 2; i >= 0; --i)
        { store_max[i] = max(store_max[i + 1], events[i][2]); }

        auto result = 0;

        // Iteration through events
        for (auto i = 0; i < events.size(); ++i) {

            // Binary search next event by upper_bound 
            auto it = upper_bound(events.begin() + i, events.end(), events[i][1], [](auto const& value, auto const& vec) {
                return value < vec[0];
            });

            // Check iterator
            if (it not_eq events.end()) {
                // Get index for store_max
                auto indx = abs(distance(it, events.begin()));

                // Compare result and new_max_value
                result = max(result, events[i][2] + store_max[indx]);
            }
            result = max(result, events[i][2]);
        }

        return result;
    }
};