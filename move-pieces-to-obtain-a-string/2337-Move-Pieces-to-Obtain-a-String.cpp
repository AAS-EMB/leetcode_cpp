class Solution {
public:
    bool canChange(string start, string target) {
        const auto Size = start.size();

        for (auto i = 0, j = 0; i < Size or j < Size; ++i, ++j) {
            while (i < Size and start[i]  == '_') ++i;
            while (j < Size and target[j] == '_') ++j;

            auto c = start[i];
            if (c not_eq target[j] or \
                c == 'L' and i < j or \
                c == 'R' and i > j)
                return false;
        }

        return true;
    }
};