class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector letters(26, 0);

        for (auto i = 0; i < s.size(); ++i)
        {
            letters[s[i] - 'a'] = i;
        }

        vector<int> result;
        auto start = 0, l = 0;

        for (auto i = 0; i < s.size(); ++i)
        {
            l = max(l, letters[s[i] - 'a']);
            if (i == l)
            {
                result.push_back(i - start + 1);
                start = i + 1;
            }
        }

        return result;
    }
};