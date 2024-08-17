class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        int m = points.size();
        int n = points[0].size();
        vector<long long> prevRow(n, 0);

        // Start with the first row
        for (int j = 0; j < n; ++j) {
            prevRow[j] = points[0][j];
        }

        // Process the remaining rows
        for (int i = 1; i < m; ++i) {
            vector<long long> currRow(n, 0);

            // Left to right pass
            vector<long long> leftMax(n, 0);
            leftMax[0] = prevRow[0];
            for (int j = 1; j < n; ++j) {
                leftMax[j] = max(leftMax[j - 1] - 1, prevRow[j]);
            }

            // Right to left pass
            vector<long long> rightMax(n, 0);
            rightMax[n - 1] = prevRow[n - 1];
            for (int j = n - 2; j >= 0; --j) {
                rightMax[j] = max(rightMax[j + 1] - 1, prevRow[j]);
            }

            // Fill the current row with the maximum possible points
            for (int j = 0; j < n; ++j) {
                currRow[j] = points[i][j] + max(leftMax[j], rightMax[j]);
            }

            // Update previous row for the next iteration
            prevRow = currRow;
        }

        // The maximum points will be the maximum value in the last row
        return *max_element(prevRow.begin(), prevRow.end());
    }
};
