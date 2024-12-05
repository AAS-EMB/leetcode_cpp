class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // Sorting vector
        sort(nums.begin(), nums.end());
        
        // Output result
        vector<vector<int>> result;
        
        // Exclude duplicate
        set<vector<int>> sv;

        // Iteration and find 3sum (i - first, j - next, k - last)
        for (auto i = 0; i < nums.size(); ++i) {
            auto j = i + 1;
            auto k = nums.size() - 1;

            // Find j & k
            while (j < k) {
                auto sum = nums[i] + nums[j] + nums[k];

                if (sum == 0) {
                    sv.insert( { nums[i], nums[j], nums[k] } );
                    ++j;
                    --k;
                } else if (sum < 0) {
                    ++j;
                } else {
                    --k;
                }
            }
        }

        // Make output result
        for (auto & triplet : sv) {
            result.push_back(move(triplet));
        }

        return result;
    }
};