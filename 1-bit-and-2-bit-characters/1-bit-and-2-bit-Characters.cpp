class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        auto i = 1;
        for ( ; i < bits.size(); )
        {
            if (bits[i - 1] == 0)
            {
                ++i;
            }
            else if ((bits[i - 1] == 1 and bits[i] == 0) or (bits[i - 1] == 1 and bits[i] == 1))
            {
                i += 2;
            }
            else
            {
                terminate();
            }
        }

        return i == bits.size();
    }
};