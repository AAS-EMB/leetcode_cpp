class Solution {
public:
    int lengthOfLastWord(string s) {
        auto counter = 0;
        auto last_c  = s[0];

        for (auto const& c : s) {
            if (c != ' ' && last_c == ' ')
            { counter = 0; }

            if (c != ' ')
            { ++counter; }

            last_c = c;
        }

        return counter;
    }
};