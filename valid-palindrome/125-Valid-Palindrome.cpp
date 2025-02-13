class Solution {
public:
    bool isPalindrome(string s) {
        std::string filtered;

        for (auto const& c : s) {
            if (std::isalnum(c)) { filtered += std::tolower(c); }
        }

        int begin = 0;
        int end   = filtered.size() - 1;

        while (begin < end) {

            if (filtered[begin] not_eq filtered[end]) {
                return false;
            }

            ++begin;
            --end;
        }

        return true;
    }
};