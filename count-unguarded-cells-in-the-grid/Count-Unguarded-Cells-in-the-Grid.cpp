class Solution {
public:

    void fill_guard_direction(vector<int>& spare, int row, int column, int m, int n, int dr, int dc)
    {
        row    += dr;
        column += dc;
        while (row >= 0 && row < m && column >= 0 && column < n)
        {
            const auto index = row * n + column;

            // если стена или охранник — останавливаемся
            if (spare[index] == 0)
                break;

            // помечаем как охраняемую клетку
            spare[index] = -1;

            row += dr;
            column += dc;
        }
    }

    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<int> spare(m * n, 1);

        // set wall
        for (auto const& wall : walls)
        {
            const auto index = wall[0] * n + wall[1];
            spare[wall[0] * n + wall[1]] = 0;
        }

        // set guards
        for (auto const& guard : guards)
        {
            const auto index = guard[0] * n + guard[1];
            spare[index] = 0;
        }

        // направления: вверх, вниз, влево, вправо
        const int dirs[4][2] = { {-1,0}, {1,0}, {0,-1}, {0,1} };

        for (auto const& guard : guards)
        {
            for (auto const& d : dirs)
            {
                fill_guard_direction(spare, guard[0], guard[1], m, n, d[0], d[1]);
            }
        }

        return count(spare.begin(), spare.end(), 1);
    }
};