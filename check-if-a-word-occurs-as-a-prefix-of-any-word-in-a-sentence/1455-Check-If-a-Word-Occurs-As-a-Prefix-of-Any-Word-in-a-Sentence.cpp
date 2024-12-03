#include <sstream>

class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        using namespace std;

        istringstream ss(sentence);
        auto word  = ""s;
        auto index = 1;

        while (ss >> word) {
            if (word.find(searchWord) == 0) { return index; }
            ++index;
        }

        return -1;
    }
};