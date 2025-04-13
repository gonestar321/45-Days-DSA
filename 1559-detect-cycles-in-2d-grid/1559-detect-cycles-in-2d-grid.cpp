class Solution {
public:
    int m, n;
    vector<vector<bool>> visited;
    
    bool dfs(vector<vector<char>>& grid, int x, int y, int fromX, int fromY, char ch) {
        if (visited[x][y]) return true;

        visited[x][y] = true;

        vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        for (auto [dx, dy] : directions) {
            int newX = x + dx;
            int newY = y + dy;

            if (newX < 0 || newY < 0 || newX >= m || newY >= n) continue;
            if (grid[newX][newY] != ch) continue;
            if (newX == fromX && newY == fromY) continue;  // Don't go back to previous cell

            if (dfs(grid, newX, newY, x, y, ch)) return true;
        }

        return false;
    }
    
    bool containsCycle(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();
        visited = vector<vector<bool>>(m, vector<bool>(n, false));

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (!visited[i][j]) {
                    if (dfs(grid, i, j, -1, -1, grid[i][j])) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};
