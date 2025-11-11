class Solution {
public:
    int minOperations(vector<int>& nums) {
        vector<int> st;
        auto result = 0;

        for (auto const& n : nums)
        {
            while ((not st.empty()) and st.back() > n)
            {
                st.pop_back();
            }

            if (n == 0) continue;
            if (st.empty() or st.back() < n)
            {
                ++result;
                st.push_back(n);
            }
        }

        return result;
    }
};