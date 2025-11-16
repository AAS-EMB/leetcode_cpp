class Solution {
public:
    int numSub(string s) {
        long long result = 0ll, counter = 0ll;
        constexpr long long MOD = 1'000'000'007;

        for (auto i = 0; i < s.size(); ++i)
        {
            if (s[i] == '1')
            {
                ++counter;
            }
            else
            {
                result = (result + counter * (counter + 1) / 2) % MOD;
                counter = 0;
            }
        }

        result = (result + counter * (counter + 1) / 2) % MOD;

        return static_cast<int>(result);
    }
};