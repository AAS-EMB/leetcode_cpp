class Solution {
public:
    int strStr(string haystack, string needle) {
        int res = -1;
        for(auto i = 0; i < haystack.length(); ++i) {
            if(haystack[i] == needle[0]) {
                auto has_needle = true;
                for(auto j = 1; j < needle.length(); ++j) {
                    if(haystack[i + j] != needle[j]) {
                        has_needle = false;
                        break;
                    }
                }
                if(has_needle) {
                    res = i;
                    break;
                }
            }
        }
        return res;
    }
};