class Solution {
public:
    int trailingZeroes(int n) {
        auto result = 0;

        while (n > 0)
        {
            n /= 5;
            result += n;
        }

        return result;
    }
};