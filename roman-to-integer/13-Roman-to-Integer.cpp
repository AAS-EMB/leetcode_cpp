class Solution {
public:
    int romanToInt(string s) {
        int res = 0;
        for(auto it = 0; it < s.size(); it++) {
            switch(s[it]) {
                case 'I': {
                    if(s[it + 1] == 'V') {
                        res += 4;
                        it++;
                    } else if(s[it + 1] == 'X') {
                        res += 9;
                        it++;
                    } else {
                        res += 1;
                    }
                    break;
                }
                case 'V': {
                    res += 5;
                    break;
                }
                case 'X': {
                    if(s[it + 1] == 'L') { 
                        res += 40;
                        it++;
                    } else if(s[it + 1] == 'C') {
                        res += 90;
                        it++;
                    } else {
                        res += 10;
                    }
                    break;
                }
                case 'L': {
                    res += 50;
                    break;
                }
                case 'C': {
                    if(s[it + 1] == 'D') { 
                        res += 400;
                        it++;
                    } else if(s[it + 1] == 'M') {
                        res += 900;
                        it++;
                    } else {
                        res += 100;
                    }
                    break;
                }
                case 'D': {
                    res += 500;
                    break;
                }
                case 'M': {
                    res += 1000;
                    break;
                }
            }
        }
        return res;
    }
};