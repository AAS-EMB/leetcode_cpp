class Solution {
public:
    int maxProfit(vector<int>& prices) {
        auto profit = 0;
        const auto n = prices.size();
        auto l = 0;
        auto r = 1;

        while (r not_eq n) {
            if (prices[r] > prices[l])
                profit = max(profit, prices[r] - prices[l]);
            else
                l = r;
            ++r;
        }

        return profit;
    }
};