class Solution {
public:
    int maxArea(vector<int>& height) {
        using namespace std;

        auto left = 0;
        auto right = height.size() - 1;
        auto max_area = 0;

        while (right > left) {

            if (auto area = min(height[left], height[right]) * (right - left); area > max_area) {
                max_area = area;
            }

            (height[left] < height[right]) ? ++left : --right;
        }
        return max_area;
    }
};