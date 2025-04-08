class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        queue<tuple<int, int, int>> q;
        vector<vector<bool>> vis(n, vector<bool>(m, false));

        // Multi-source BFS: saare rotten oranges (2) queue mein daal do with time = 0
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j, 0});
                    vis[i][j] = true;
                }
            }
        }

        int delRow[] = {0, -1, 0, 1};
        int delCol[] = {-1, 0, 1, 0};
        int maxTime = 0;

        // BFS traversal
        while (!q.empty()) {
            auto [row, col, time] = q.front();
            q.pop();

            maxTime = max(maxTime, time);

            for (int k = 0; k < 4; k++) {
                int newRow = row + delRow[k];
                int newCol = col + delCol[k];

                if (newRow >= 0 && newRow < n &&
                    newCol >= 0 && newCol < m &&
                    grid[newRow][newCol] == 1 &&
                    !vis[newRow][newCol]) {

                    q.push({newRow, newCol, time + 1});
                    vis[newRow][newCol] = true;
                    grid[newRow][newCol] = 2;
                }
            }
        }

        // Check if any fresh orange is still left
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) return -1;
            }
        }

        return maxTime;
    }
};
