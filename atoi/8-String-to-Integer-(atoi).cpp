#include <limits>

class Solution {
public:
    int myAtoi(string s) {
        using namespace std;

        int sign{numeric_limits<int>::min()};
        int res{0};
        constexpr int Base = 10;

        for(int i = 0; i < s.size(); ++i) {
            if(sign == numeric_limits<int>::min() and s[i] == ' ') {
                continue;
            } else if(sign == numeric_limits<int>::min() and (s[i] == '-' or s[i] == '+')) {
                sign = (s[i] == '-') * -1;
            } else if(s[i] >= '0' and s[i] <= '9') {
                if(sign == numeric_limits<int>::min()) { sign = 0; }
                if (res > numeric_limits<int>::max() / Base or (res == numeric_limits<int>::max() / Base and s[i] - '0' > 7)) {
                    return sign == 0 ? numeric_limits<int>::max() : numeric_limits<int>::min();
                }
                res = res * Base + (s[i] - '0');
            } else {
                break;
            }
        }

        return sign == 0 ? res : res * sign;
    }
};