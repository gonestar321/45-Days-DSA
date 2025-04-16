class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        // multi source bfs from all zeros
        int n = mat.size();
        int m = mat[0].size();

        vector<vector<bool>> vis( n , vector<bool>(m,false));
        vector<vector<int>> dist (n, vector<int>(m,0));

        queue<pair<int,int>> q;

        for( int i = 0 ; i < n ; i++){
            for( int j = 0 ; j < m ; j++){
                if( mat[i][j] == 0 && vis[i][j]== false ){
                    q.push({i , j });
                }
            }
        }

        int delRow[] = { 0 , -1 , 0 , 1 };
        int delCol[] = { -1 , 0 , 1 , 0 };

            while(!q.empty()){
                
                pair<int,int> node = q.front();
                q.pop();

                auto[row , col ] = node;

                for( int k = 0 ; k < 4 ; k++){
                    int newRow = row + delRow[k];
                    int newCol = col + delCol[k];

                    if(newRow >= 0 && newRow < n && newCol >= 0 && newCol < m
                            && !vis[newRow][newCol]) {
                                dist[newRow][newCol] = dist[row][col] + 1;
                                vis[newRow][newCol] = true;
                                q.push({newRow, newCol});
                    }
                }

                
            }
            return dist;
    }
};