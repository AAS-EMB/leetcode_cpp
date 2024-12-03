#include <limits>

class Solution {
public:
    int reverse(int x) {
        static constexpr auto Base = 10;
        auto result = 0;

        while (x not_eq 0) {
            auto digit = x % Base;
            x /= Base;
            if (result > numeric_limits<int>::max() / Base or \\
                result < numeric_limits<int>::min() / Base) {
                return 0;
            }
            result = result * Base + digit;
        }

        return result;
    }
};

// while (x != 0) {
//             int pop = x % 10;
//             x /= 10;
//             if (rev > INT_MAX/10 || (rev == INT_MAX / 10 && pop > 7)) return 0;
//             if (rev < INT_MIN/10 || (rev == INT_MIN / 10 && pop < -8)) return 0;
//             rev = rev * 10 + pop;
//         }
//         return rev;