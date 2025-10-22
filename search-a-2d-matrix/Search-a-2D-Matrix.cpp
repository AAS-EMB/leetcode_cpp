class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int left = 0;
        int right = matrix.size() - 1;
        int row = 0;

        while (right >= left)
        {
            int mid = (left + right) / 2;

            if (matrix[mid][0] <= target and target <= matrix[mid][matrix[mid].size() - 1])
            {
                row = mid;
                break;
            }
            else if (matrix[mid][0] > target)
            {
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }

        {
            int left  = 0;
            int right = matrix[row].size() - 1;

            while (right >= left)
            {
                int mid = (left + right) / 2;

                if (target > matrix[row][mid])
                {
                    left = mid + 1;
                }
                else if (target < matrix[row][mid])
                {
                    right = mid - 1;
                }
                else
                {
                    return true;
                }
            }
        }

        return false;
    }
};