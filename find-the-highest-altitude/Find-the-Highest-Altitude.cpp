class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        auto result   = 0;
        auto altitude = 0;

        for (auto i = 0; i < gain.size(); ++i) {
            altitude = altitude + gain[i];
            result = max(result, altitude);
        }

        return result;
    }
};