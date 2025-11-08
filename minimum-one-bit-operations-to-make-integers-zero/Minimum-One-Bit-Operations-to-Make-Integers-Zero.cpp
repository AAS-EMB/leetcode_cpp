class Solution {
public:
    int minimumOneBitOperations(int n) {
        int result = 0, k = 0, mask = 1;

        while (mask <= n)
        {
            if ((n & mask) not_eq 0)
            {
                result = (1 << (k + 1)) - 1 - result;
            }

            mask <<= 1;
            ++k;
        }

        return result;
    }
};