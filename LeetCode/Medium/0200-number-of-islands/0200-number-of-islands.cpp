class Solution {
    private: 
        void bfs(vector<vector<char>>& grid , vector<vector<bool>>& vis  , int x , int y ){
            queue<pair<int,int>> q;
            q.push({x , y} );

            vector<int> dx = { 0 , -1 , 0 , 1 };
            vector<int> dy = { -1 , 0 , 1 , 0 };

            while( !q.empty()){

            int nodeX = q.front().first;
            int nodeY = q.front().second;
                q.pop();
                
                for( int i = 0 ; i < 4 ; i++ ){
                    int newX = nodeX + dx[i];
                    int newY = nodeY + dy[i];

                    if(newX>=0 && newX < grid.size()&& newY >=0 && newY<grid[0].size()&&
                        !vis[newX][newY] && grid[newX][newY] == '1' ){
                            q.push({newX, newY});
                            vis[newX][newY] = true;
                        }

                }
            }

        }
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<bool>> vis( n , vector<bool>(m,false));
        int count = 0;

        for( int i = 0 ; i < n ; i++ ){
            for( int j = 0 ;  j <  m ; j++ ){
                if( !vis[i][j] && grid[i][j] == '1' ){
                    count++ ;
                    bfs( grid ,  vis , i , j );
                }
            }
        }
        return count;
    }
};