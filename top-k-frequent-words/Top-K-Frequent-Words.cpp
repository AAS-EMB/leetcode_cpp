class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> store;

        for (auto const& w : words)
        {
            ++store[w];
        }

        using QueueT = pair<string, int>;
        struct func
        {
            auto operator()(QueueT const& lhs, QueueT const& rhs) -> bool
            {
                return lhs.second > rhs.second || (lhs.second == rhs.second and lhs.first < rhs.first);
            }
        };
        priority_queue<QueueT, std::vector<QueueT>, func> q;
        for (auto const& [key, value] : store)
        {
            q.push({ key, value });
            if (q.size() > k)
                q.pop();
        }

        vector<string> result(k);
        int i = k - 1;

        while (not q.empty())
        {
            result[i--] = q.top().first;
            q.pop();
        }

        return result;
    }
};