class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        // Store the row and column indices where 0 is found
        vector<int> rowArr;
        vector<int> rowCol;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == 0) {
                    rowArr.push_back(i);
                    rowCol.push_back(j);
                }
            }
        }

        // Set entire rows to 0
        for (int i = 0; i < rowArr.size(); i++) {
            int row = rowArr[i];
            for (int j = 0; j < m; j++) {
                matrix[row][j] = 0;
            }
        }

        // Set entire columns to 0
        for (int i = 0; i < rowCol.size(); i++) {
            int col = rowCol[i];
            for (int j = 0; j < n; j++) {
                matrix[j][col] = 0;
            }
        }
    }
};
