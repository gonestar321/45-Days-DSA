class Solution {

    private:
    void bfs(vector<vector<int>>& grid, vector<vector<bool>>& vis, int i, int j) {
        queue<pair<int, int>> q;
        q.push({i, j});
        vis[i][j] = true;
        
        int delX[] = {0, -1, 0, 1};
        int delY[] = {-1, 0, 1, 0};
        
        while (!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for (int k = 0; k < 4; k++) {
                int nRow = row + delX[k];
                int nCol = col + delY[k];

                if (nRow >= 0 && nRow < grid.size() && nCol >= 0 && nCol < grid[0].size() &&
                    grid[nRow][nCol] == 1 && !vis[nRow][nCol]) {
                    vis[nRow][nCol] = true;
                    q.push({nRow, nCol});
                }
            }
        }
    }

public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<bool>> vis(n, vector<bool>(m, false));

        // First, mark all boundary cells connected with the boundary using BFS
        for (int i = 0; i < m; i++) {
            if (grid[0][i] == 1 && !vis[0][i]) {
                bfs(grid, vis, 0, i);
            }
            if (grid[n-1][i] == 1 && !vis[n-1][i]) {
                bfs(grid, vis, n-1, i);
            }
        }

        for (int i = 0; i < n; i++) {
            if (grid[i][0] == 1 && !vis[i][0]) {
                bfs(grid, vis, i, 0);
            }
            if (grid[i][m-1] == 1 && !vis[i][m-1]) {
                bfs(grid, vis, i, m-1);
            }
        }

        // Now, count the number of enclaves (unvisited 1's)
        int enclaves = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1 && !vis[i][j]) {
                    enclaves++;
                }
            }
        }

        return enclaves;
    }
};
