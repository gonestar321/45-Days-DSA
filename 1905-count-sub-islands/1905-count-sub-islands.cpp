class Solution {
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int rows = grid2.size();
        int cols = grid2[0].size();
        int count = 0;

        // DFS function to explore the island
        function<bool(int, int)> dfs = [&](int i, int j) -> bool {
            if (i < 0 || j < 0 || i >= rows || j >= cols || grid2[i][j] == 0) {
                return true;
            }

            grid2[i][j] = 0;  // Mark this cell as visited
            bool isValid = grid1[i][j] == 1;  // Check if it's a valid sub-island

            // Explore all four directions
            isValid &= dfs(i + 1, j);
            isValid &= dfs(i - 1, j);
            isValid &= dfs(i, j + 1);
            isValid &= dfs(i, j - 1);

            return isValid;
        };

        // Iterate through each cell in grid2
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (grid2[i][j] == 1) {
                    // If the sub-island is valid, increment the count
                    if (dfs(i, j)) {
                        ++count;
                    }
                }
            }
        }

        return count;
    }
};
