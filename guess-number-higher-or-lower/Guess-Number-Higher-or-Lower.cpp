/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        size_t left = 0, right = n;
        size_t mid = (left + right) / 2;
        auto r = guess(mid);

        while (r not_eq 0)
        {
            if (r == 1)
            {
                left = mid + 1;
                mid = (left + right) / 2;
            }
            else
            {
                right = mid - 1;
                mid = (left + right) / 2;
            }
            r = guess(mid);
        }

        return mid;
    }
};