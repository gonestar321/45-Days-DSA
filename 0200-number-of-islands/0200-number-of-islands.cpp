class Solution {

private:

void bfs(vector<vector<char>>& grid , vector<vector<bool>>& vis , int i , int j ){
    vis[i][j] = true;
    queue<pair<int,int>> q;
    q.push({i , j});
    int difx[] ={0 , -1 , 0 , 1} ;
    int dify[] ={-1 , 0 , 1 , 0} ;

    while( !q.empty()){
      pair<int,int> node = q.front();
        q.pop();
      int x = node.first;
      int y = node.second;

      for(int n = 0; n <4; n++){
            int newrow = x + difx[n];
            int newcol = y + dify[n];
            if(newrow>= 0 && newrow< grid.size() && newcol>=0 && newcol<grid[0].size() &&grid[newrow][newcol]=='1' && vis[newrow][newcol] == false){
                q.push({newrow,newcol});
                vis[newrow][newcol] = true;
            
        }
      }
    }

}







public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size(); //rows
        int m = grid[0].size(); //cols

        vector<vector<bool>> vis (n, vector<bool>(m,false));
        int islands = 0;
        for( int i = 0 ; i<n ; i++ ){
            for( int j = 0; j < m ; j++ ){
                if( vis[i][j]== false && grid[i][j]== '1' ){
                    islands++;
                    bfs(grid , vis , i , j);
                }
            }
        }
        return islands;

    }
};