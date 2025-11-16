class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> mat(n, vector<int>(n, 0));

        for (auto const& q : queries)
        {
            auto [top_row, top_col] = tie(q[0], q[1]);
            auto [bot_row, bot_col] = tie(q[2], q[3]);

            for (auto x = top_row; x <= bot_row; ++x)
            {
                for (auto y = top_col; y <= bot_col; ++y)
                {
                    ++mat[x][y];
                }
            }
        }
        return mat;
    }
};