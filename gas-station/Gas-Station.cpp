class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        auto total_gas = 0, total_cost = 0;
        auto current_gas = 0, start = 0;

        for (auto i = 0; i < gas.size(); ++i) {
            total_gas += gas[i];
            total_cost += cost[i];

            current_gas += gas[i] - cost[i];

            if (current_gas < 0) {
                start = i + 1;
                current_gas = 0;
            }
        }

        return (total_gas < total_cost) ? -1 : start;
    }
};