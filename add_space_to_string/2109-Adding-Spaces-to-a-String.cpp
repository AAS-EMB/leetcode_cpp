class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        using namespace std;

        auto last_index = 0;
        string result   = ""s;

        for (auto const& index : spaces) {
            result    += move(s.substr(last_index, index - last_index));
            result    += ' ';
            last_index = index;
        }

        result += move(s.substr(last_index));

        return result;
    }
};