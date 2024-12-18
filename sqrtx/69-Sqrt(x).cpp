class Solution {
public:
    int mySqrt(int x) {
        if(x == 0 || x == 1) {
            return x;
        }
        int res = 0;
        for(auto i = 0u; i < x; ++i) {
            auto tmp = i * i;
            if(tmp <= x) {
                res = i;
            } else {
                break;
            }
        }
        return res;
    }
};