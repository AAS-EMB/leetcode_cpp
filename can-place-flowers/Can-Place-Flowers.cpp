class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        auto count = 0;

        for (auto it = flowerbed.begin(); it not_eq flowerbed.end(); ++it)
        {
            if (*it == 0)
            {
                auto is_empty_l = (it == flowerbed.begin()) or (*prev(it) == 0);
                auto is_empty_r = (next(it) == flowerbed.end()) or (*next(it) == 0);

                if (is_empty_l and is_empty_r)
                {
                    *it = 1;
                    ++count;
                }
            }
        }

        return count >= n;
    }
};