class Solution {
public:
    void callDFS(int x, int y, vector<vector<int>>& matrix,
                 vector<vector<bool>>& visited,
                 vector<int>& dx, vector<int>& dy,
                 vector<int>& answer, int dir) {

        int n = matrix.size();
        int m = matrix[0].size();

        answer.push_back(matrix[x][y]);
        visited[x][y] = true;

        for (int i = 0; i < 4; ++i) {
            int newDir = (dir + i) % 4;
            int newX = x + dx[newDir];
            int newY = y + dy[newDir];

            if (newX >= 0 && newX < n && newY >= 0 && newY < m &&
                !visited[newX][newY]) {
                callDFS(newX, newY, matrix, visited, dx, dy, answer, newDir);
                return; // spiral goes only one direction at a time
            }
        }
    }

    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size();
        if (n == 0) return {};
        int m = matrix[0].size();

        vector<int> dx = {0, 1, 0, -1};  // right, down, left, up
        vector<int> dy = {1, 0, -1, 0};

        vector<vector<bool>> visited(n, vector<bool>(m, false));
        vector<int> answer;

        callDFS(0, 0, matrix, visited, dx, dy, answer, 0);

        return answer;
    }
};
