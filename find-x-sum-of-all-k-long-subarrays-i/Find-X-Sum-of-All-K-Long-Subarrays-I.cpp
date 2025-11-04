class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        vector<int> result(nums.size() - k + 1, 0);
        auto begin = 0, end = begin + k;

        for (auto & item : result)
        {
            unordered_map<int, int> um;
            for (auto i = begin; i < end; ++i)
            {
                ++um[nums[i]];
            }

            vector<pair<int, int>> freq;
            for (auto const& [key, value] : um)
            {
                freq.emplace_back(value, key);
            }
            sort(freq.begin(), freq.end(), greater<pair<int, int>>());

            auto xsum = 0;
            for (auto i = 0; i < x and i < freq.size(); ++i)
            {
                xsum += freq[i].first * freq[i].second;
            }
            item = xsum;

            ++begin;
            end = begin + k;
        }

        return result;
    }
};