class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        const auto compare = [] (char src, char target) noexcept {
            if (src == target)
            { return true; }

            int next = static_cast<int>(src)  + 1;

            if (next < 'a') { next += 26; }
            if (next > 'z') { next -= 26; }

            return static_cast<char>(next) == target;
        };

        int passed_size = 0;
        int index       = 0;

        for (auto const& c : str1) {
            if (compare(c, str2[index])) {
                ++passed_size;
                ++index;
                if (passed_size == str2.size()) {
                    return true;
                }
            }
        }

        return false;
    }
};