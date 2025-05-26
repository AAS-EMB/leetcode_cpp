class Solution {
public:
    bool isHappy(int n) {
        std::unordered_set<int> s;

        while (n not_eq 1 and s.count(n) == 0) {
            s.insert(n);
            n = next_num(n);
        }

        return n == 1;
    }

private:
    int next_num(int n) {
        int new_n = 0;

        while (n not_eq 0) {
            int num = n % 10;
            new_n += (num * num);
            n /= 10;
        }

        return new_n;
    }
};