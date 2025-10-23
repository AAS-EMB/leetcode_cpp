class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int count = 0;
        
        for (auto i = 0; i < n; ++i)
        {
            for (auto j = 0; j < m; ++j)
            {
                if (grid[i][j] == '1')
                {
                    ++count;
                    dfs(grid, i, j);
                }
            }
        }

        return count;
    }

    void dfs(vector<vector<char>>& grid, int i, int j)
    {
        int n = grid.size(), m = grid[0].size();

        if (i < 0 or j < 0 or i >= n or j >= m or grid[i][j] == '0')
        {
            return;
        }

        grid[i][j] = '0';

        dfs(grid, i + 1, j);
        dfs(grid, i - 1, j);
        dfs(grid, i, j + 1);
        dfs(grid, i, j - 1);
    }
};