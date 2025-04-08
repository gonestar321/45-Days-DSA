class Solution {
private:
    void bfs(vector<vector<int>> &grid, vector<vector<bool>> &vis, int i, int j, int &maxTime) {
        queue<tuple<int, int, int>> q;
        q.push({i, j, 0});  // Start time = 0
        vis[i][j] = true;

        int delRow[] = {-1, 0, 0, 1};
        int delCol[] = {0, -1, 1, 0};

        while (!q.empty()) {
            auto [rowNo, colNo, time] = q.front(); // ye wala time hi 'minute' hai
            q.pop();
            maxTime = max(maxTime, time); // har level pe maxTime update karte chalo

            for (int k = 0; k < 4; k++) {
                int newRow = rowNo + delRow[k];
                int newCol = colNo + delCol[k];

                if (newRow >= 0 && newRow < grid.size() &&
                    newCol >= 0 && newCol < grid[0].size() &&
                    grid[newRow][newCol] == 1 && vis[newRow][newCol] == false) {

                    q.push({newRow, newCol, time + 1}); // agla minute mein ye orange bhi rotten hoga
                    vis[newRow][newCol] = true;         // ✅ mark visited
                    grid[newRow][newCol] = 2;           // ✅ mark as rotten
                }
            }
        }
    }

public:
    int orangesRotting(vector<vector<int>> &grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<bool>> vis(n, vector<bool>(m, false));
        int maxTime = 0;

        // ⚠️ Multi-source BFS — saare rotten oranges ek saath queue mein bhejna chahiye
        // Tum single-source kar rahe ho — toh galat result aayega
        queue<tuple<int, int, int>> q;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j, 0}); // Sab rotten oranges ko ek sath daalo queue mein
                    vis[i][j] = true;
                }
            }
        }

        int delRow[] = {-1, 0, 0, 1};
        int delCol[] = {0, -1, 1, 0};

        while (!q.empty()) {
            auto [row, col, time] = q.front();
            q.pop();
            maxTime = max(maxTime, time);

            for (int k = 0; k < 4; k++) {
                int newRow = row + delRow[k];
                int newCol = col + delCol[k];

                if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m &&
                    grid[newRow][newCol] == 1 && vis[newRow][newCol] == false) {

                    q.push({newRow, newCol, time + 1});
                    vis[newRow][newCol] = true;
                    grid[newRow][newCol] = 2;
                }
            }
        }

        // \U0001f9e0 Check agar koi fresh orange bacha toh impossible hai
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) return -1;
            }
        }

        return maxTime; // ✅ this is the min time needed to rot all oranges
    }
};
