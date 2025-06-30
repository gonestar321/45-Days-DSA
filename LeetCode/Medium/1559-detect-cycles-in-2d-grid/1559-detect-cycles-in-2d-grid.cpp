class Solution {
    private:
     
     bool dfs( vector<vector<char>>& grid , int x ,  int y , vector<vector<bool>>&vis , int px , int py ){
            vis[x][y] = true;
        vector<int> dx = { 0 , -1 , 0  , 1  };
        vector<int> dy = {-1, 0 , 1 , 0 };

            for( int i =0 ; i < 4 ; i++ ){
                int newX = x + dx[i];
                int newY = y + dy[i];

                if(newX >=0 && newX < grid.size() && newY >=0 && newY< grid[0].size() 
                        && (newX != px || newY != py) && grid[newX][newY] == grid[x][y] && !vis[newX][newY]){
                            dfs( grid , newX ,newY , vis , x , y);
                        }
                else if( newX >=0 && newX < grid.size() && newY >=0 && newY< grid[0].size() 
                        && (newX != px || newY != py) && grid[newX][newY] == grid[x][y] && vis[newX][newY] ){
                            return true;
                        }

            }
            return false;
     }
public:
    bool containsCycle(vector<vector<char>>& grid) {
        // DFS bhi likh deta huu
        // bass ismein bhi I've to make sure ki parent na ho that's it !tick! 

        int n = grid.size();
        int m = grid[0].size();

        vector<vector<bool>> vis(n , vector<bool>(m,0));

        for( int i = 0 ; i < n ; i++ ){
            for( int j = 0 ;  j < m ; j++ ){
                if( !vis[i][j]){

                   if( dfs( grid , i , j  , vis , -1 , -1 )){
                    return true;
                   }
                }
            }
        }
        return false;
        







    }
};