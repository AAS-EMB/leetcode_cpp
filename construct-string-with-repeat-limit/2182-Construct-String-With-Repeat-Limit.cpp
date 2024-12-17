class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        // Store for saved repeated char symbols
        unordered_map<char, int> store;

        // Saved char symbols
        for (auto const& c : s)
        { ++store[c]; }

        // Priority queue for chars
        priority_queue<char> queue;

        // Saved chars into queue
        for (auto const& [key, value] : store)
        { queue.push(key); }

        // Result
        string repeatLimitedString;

        while (not queue.empty()) {
            // Get char from top
            auto c = queue.top();

            // Pop symbol
            queue.pop();

            // Get count
            auto count = store[c];

            // Get limit for symbol and append into relust string
            auto limit = min(count, repeatLimit);
            repeatLimitedString.append(limit, c);

            // Decrease repeated
            store[c] -= limit;

            // Check remained
            if (store[c] > 0 and not queue.empty()) {
                // Get next symbol
                auto next_c = queue.top();

                // Pop symbol
                queue.pop();

                // Push back symbol
                repeatLimitedString.push_back(next_c);
                --store[next_c];

                // Check remained symbol and return to queue
                if (store[next_c]) {
                    queue.push(next_c);
                }
                queue.push(c);
            }
        }

        return repeatLimitedString;
    }
};