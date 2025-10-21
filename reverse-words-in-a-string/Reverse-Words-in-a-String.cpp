class Solution {
public:
    string reverseWords(string s) {
        string result;
        string w;
        bool insert = false;

        for (auto it = s.begin(); it not_eq s.end(); ++it)
        {
            if (*it == ' ')
            {
                insert = true;
                continue;
            }

            if (not w.empty() and insert)
            {
                result.insert(result.begin(), w.begin(), w.end());
                result.insert(result.begin(), ' ');
                w.clear();
            }

            w.push_back(*it);
            insert = false;
        }

        if (not w.empty())
        {
            result.insert(result.begin(), w.begin(), w.end());
        }

        return result;
    }
};