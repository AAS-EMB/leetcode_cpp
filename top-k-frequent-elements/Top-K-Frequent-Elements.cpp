class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> um;

        for (auto const& num : nums)
        {
            ++um[num];
        }

        using QueueT = pair<int, int>;
        priority_queue<QueueT, vector<QueueT>, greater<QueueT>> pq;

        for (auto const& [num, counter] : um)
        {
            pq.push(QueueT{ counter, num });
            if (pq.size() > k)
            {
                pq.pop();
            }
        }

        vector<int> result(k, 0);

        for (auto & item : result)
        {
            item = pq.top().second;
            pq.pop();
        }

        return result;
    }
};