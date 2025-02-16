class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        const auto n = digits.size();

        for (int i = n - 1; i >= 0; --i) {
            
            if (digits[i] + 1 not_eq 10) {
                ++digits[i];
                return digits;
            }

            digits[i] = 0;
        }

        digits.insert(digits.begin(), 1);

        return digits;
    }
};