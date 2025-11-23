class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        auto sum = accumulate(nums.begin(), nums.end(), 0);
        auto r_11 = numeric_limits<int>::max(), r_12 = numeric_limits<int>::max();
        auto r_21 = numeric_limits<int>::max(), r_22 = numeric_limits<int>::max();

        for (auto const& num : nums)
        {
            if (num % 3 == 2)
            {
                if (r_21 > num)
                {
                    swap(r_21, r_22);
                    r_21 = num;
                }
                else
                {
                    r_22 = min(r_22, num);
                }
            }
            else if (num % 3 == 1)
            {
                if (r_11 > num)
                {
                    swap(r_11, r_12);
                    r_11 = num;
                }
                else
                {
                    r_12 = min(r_12, num);
                }
            }
        }

        auto remove_cost = numeric_limits<long long>::max();
        const auto mod = sum % 3;
        if (mod == 2)
        {
            if (r_21 not_eq numeric_limits<int>::max())
            {
                remove_cost = min(remove_cost, static_cast<long long>(r_21));
            }
            if (r_11 not_eq numeric_limits<int>::max())
            {
                remove_cost = min(remove_cost, static_cast<long long>(r_11) + static_cast<long long>(r_12));
            }
            sum -= remove_cost;
        }
        else if (mod == 1)
        {
            if (r_11 not_eq numeric_limits<int>::max())
            {
                remove_cost = min(remove_cost, static_cast<long long>(r_11));
            }
            if (r_21 not_eq numeric_limits<int>::max())
            {
                remove_cost = min(remove_cost, static_cast<long long>(r_21) + static_cast<long long>(r_22));
            }
            sum -= remove_cost;
        }

        return sum;
    }
};