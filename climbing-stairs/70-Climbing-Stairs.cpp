class Solution {
public:
    int climbStairs(int n) {
        if(n == 1) {
            return 1;
        }
        auto first_val = 1;
        auto second_val = 1;
        auto val = 0;
        for(auto i = 1; i < n; ++i) {
            val = first_val + second_val;
            first_val = second_val;
            second_val = val;
        }
        return val;
    }
};
