class Solution {
public:
    int maxDiff(int num) {
        auto replace = [&](auto x, auto y) {
            auto s = to_string(num);
            for (auto & c : s) {
                if (c - '0' == x) {
                    c = '0' + y;
                }
            }
            return s;
        };
        int min_num = num;
        int max_num = num;

        for (auto x = 0; x < 10; ++x) {
            for (int y = 0; y < 10; ++y) {
                if (auto s = replace(x, y); s[0] not_eq '0') {
                    auto res = stoi(s);
                    min_num = min(min_num, res);
                    max_num = max(max_num, res);
                }
            }
        }

        return max_num - min_num;
    }
};