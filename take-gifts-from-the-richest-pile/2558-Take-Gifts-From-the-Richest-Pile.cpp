class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {

        // Iteration until k timeout
        for (auto i = 0; i < k; ++i) {
            // Find max_element inside gifts
            auto max_it = max_element(gifts.begin(), gifts.end());

            // Get sqrt and change element
            *max_it = sqrt(*max_it);
        }

        // Accumulate gifts 
        return static_cast<long long>(accumulate(gifts.begin(), gifts.end(), 0ll));
    }
};