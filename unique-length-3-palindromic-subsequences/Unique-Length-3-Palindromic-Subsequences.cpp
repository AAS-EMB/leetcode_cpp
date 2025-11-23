class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int result = 0;
    
        // Для каждой буквы 'a'-'z' находим первое и последнее вхождение
        for (char c = 'a'; c <= 'z'; ++c) {
            int left = s.find(c);
            int right = s.rfind(c);
            
            // Если буква встречается хотя бы 2 раза
            if (left not_eq string::npos and right not_eq string::npos and left < right) {
                // Считаем уникальные буквы между первым и последним вхождением
                unordered_set<char> unique_chars;
                for (int i = left + 1; i < right; i++) {
                    unique_chars.insert(s[i]);
                }
                result += unique_chars.size();
            }
        }
    
        return result;
    }
};