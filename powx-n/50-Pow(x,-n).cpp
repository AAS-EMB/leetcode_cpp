class Solution {
public:
    double myPow(double x, int n) {
        auto result   = 1.0;
        auto pow      = n * 1l;
        auto negative = n < 0;

        if (negative) { pow *= -1; }

        while (pow > 0) {
            // If power is odd, multiply x with result
            if (pow % 2 == 1) { result *= x; }

            // n must be even now
            pow /= 2;
            x   *= x;// Change x to x^2
        }

        return negative ? 1.0 / result : result;
    }
};