class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {

        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        for (auto const& str : strs)
        {
            auto zero_count = count(str.begin(), str.end(), '0');
            auto one_count  = count(str.begin(), str.end(), '1');

            for (auto i = m; i >= zero_count; --i)
            {
                for (auto j = n; j >= one_count; --j)
                {
                    dp[i][j] = max(
                        dp[i][j],
                        dp[i - zero_count][j - one_count] + 1
                    );
                }
            }
        }

        return dp[m][n];
    }
};