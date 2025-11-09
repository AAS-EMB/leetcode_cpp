class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> result(n + 1, 0);
        int sub = 1;

        for (auto i = 1; i <= n; ++i)
        {
            if (sub * 2 == i)
            {
                sub = i;
            }
            result[i] = result[i - sub] + 1;
        }

        return result;
    }
};