class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        // sort(banned.begin(), banned.end());
        auto result = 0;
        auto sum = 0;
        for (auto i = 0; i < n; ++i) {
            if (find(banned.begin(), banned.end(), i + 1) == end(banned)) {
                sum += (i + 1);
                if (sum > maxSum) break;
                ++result;
            }
        }
        return result;
    }
};