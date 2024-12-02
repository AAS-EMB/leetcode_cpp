class Solution {
public:
    bool isPalindrome(int x) {

        if (x < 0)
        { return false; }

        auto const original = x;
        auto ld             = 0ul;
        auto rev            = 0ul;
        constexpr auto Base = 10; 

        while (x not_eq 0) {
            ld  = x % Base;
            rev = rev * Base + ld;
            x  /= Base;
        }

        return original == rev;
    }
};
