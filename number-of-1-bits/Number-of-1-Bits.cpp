class Solution {
public:
    int hammingWeight(int n) {
        auto result = 0;

        while (n) {
            result += (n & 0b1);
            n >>= 1;
        }

        return result;
    }
};