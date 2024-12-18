class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        
        // i
        for (auto i = 0; i < prices.size(); ++i) {
            for (auto j = i + 1; j < prices.size(); ++j) {
                if (prices[j] <= prices[i]) {
                    prices[i] -= prices[j];
                    break;
                }
            }
        }

        return prices;
    }
};