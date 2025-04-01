class Solution {
    auto split_words(string s) {
        std::istringstream iss(s);
        std::string word;
        std::vector<string> out;

        while (std::getline(iss, word, ' ')) {
            out.push_back(word);
        }

        return out;
    }
public:
    bool wordPattern(string pattern, string s) {
        auto words = split_words(s);

        if (words.size() not_eq pattern.size()) {
            return false;
        }

        std::unordered_map<char, std::string> char_word;
        std::unordered_map<std::string, char> word_char;

        for (auto i = 0; i < pattern.size(); ++i) {
            auto c = pattern[i];
            auto word = words[i];

            if (char_word.count(c)) {
                if (char_word[c] not_eq word) {
                    return false;
                }
            } else {
                if (word_char.count(word) and word_char[word] not_eq c) {
                    return false;
                }
                char_word[c] = word;
                word_char[word] = c;
            }
        }

        return true;
    }

};