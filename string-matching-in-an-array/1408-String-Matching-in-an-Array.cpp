class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        vector<string> result;

        for (auto i = 0; i < words.size(); ++i) {
            auto lps = make_lps(words[i]);

            for (auto j = 0; j < words.size(); ++j) {
                if (i == j) { continue; }
                if (match(words[i], words[j], lps)) {
                    result.push_back(words[i]);
                    break;
                }
            }
        }

        return result;
    }

    vector<int> make_lps(string const& pat) {
        auto len = 0;
        auto cur = 1;
        vector<int> lps(pat.size(), 0);

        while (cur < pat.size()) {
            if (pat[cur] == pat[len]) {
                ++len;
                lps[cur] = len;
                ++cur;
            } else {
                if (len > 0) {
                    len = lps[len - 1];
                } else {
                    ++cur;
                }
            }
        }

        return lps;
    }

    bool match(string const& pat, string const& str, vector<int> const& lps) {
        auto str_indx = 0;
        auto pat_indx  = 0;

        while (str_indx < str.size()) {
            if (str[str_indx] == pat[pat_indx]) {
                ++str_indx;
                ++pat_indx;
                if (pat_indx == pat.size()) return true;
            } else {
                if (pat_indx > 0) {
                    pat_indx = lps[pat_indx - 1];
                } else {
                    ++str_indx;
                }
            }
        }

        return false;
    }
};