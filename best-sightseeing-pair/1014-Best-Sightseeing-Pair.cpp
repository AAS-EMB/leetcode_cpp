class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        const auto n = values.size();
        auto result = 0;
        auto max_left_score = values[0];

        for (auto i = 1; i < n; ++i) {
            auto max_right_score = values[i] - i;

            result = max(result, max_left_score + max_right_score);

            auto cur_left_score = values[i] + i;

            max_left_score = max(max_left_score, cur_left_score);
        }

        return result;
    }

};