class Solution {
public:
    bool isAnagram(const std::string& s1, const std::string& s2) {
        if (s1.size() not_eq s2.size())
        {
            return false;
        }

        std::vector<int> freq(26, 0);

        for (auto const& c : s1) freq[static_cast<unsigned char>(c) - 'a']++;
        for (auto const& c : s2) freq[static_cast<unsigned char>(c) - 'a']--;

        for (auto const& f : freq)
        {
            if (f not_eq 0)
            {
                return false;
            }
        }

        return true;
    }

    vector<int> findAnagrams(string s, string p) {
        unordered_map<int, string> table;
        vector<int> result;
        
        for (auto i = 0; i < s.size(); ++i)
        {
            auto substr = s.substr(i, p.size());

            if (substr.size() == p.size())
            {
                table[i] = substr;
            }
        }

        for (auto const& [index, s] : table)
        {
            if (isAnagram(s, p))
            {
                result.push_back(index);
            }
        }

        return result;
    }
};