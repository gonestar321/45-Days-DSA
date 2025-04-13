class Solution {

private: 

    bool bfs( vector<vector<char>>& grid , char alpha ,
             queue<tuple<int,int,int,int>> &q , vector<vector<bool>>& vis ){

            // queue is already taken by reference 
            int n = grid.size();
            int m = grid[0].size();

            while( !q.empty() ){
                tuple<int,int,int,int> node = q.front();
                q.pop();

                auto[ x , y , px , py ] = node;

                int delX[] = { 0 , -1 , 0 , 1 };
                int delY[] = { -1 , 0 , 1 , 0 };

                for( int k = 0 ; k < 4 ; k++){
                    int nextRow = x + delX[k];
                    int nextCol = y + delY[k];


                     if(nextRow >= 0 && nextRow < n && nextCol >=0 && nextCol < m && 
                                (nextRow != px || nextCol != py ) &&// out of bounds check
                                grid[nextRow][nextCol]== alpha && !vis[nextRow][nextCol] ){
                                         q.push({nextRow , nextCol , x , y});
                                         vis[nextRow][nextCol] = true;
                                }
                        
                    else if (nextRow >= 0 && nextRow < n && nextCol >= 0 && nextCol < m &&
                            vis[nextRow][nextCol] == true &&
                            (nextRow != px || nextCol != py) && grid[nextRow][nextCol]== alpha ){
                        return true;
                    }

                
                }
            } 
            return false;
    }


public:
    bool containsCycle(vector<vector<char>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<bool>> vis(n, vector<bool>(m,false));

        queue<tuple<int,int,int,int>>  q ;
        //q.push({x,y, xp , yp}) ;

        for( int i = 0 ; i < n ; i ++){
            for ( int j = 0 ; j< m ; j++){
                if( vis[i][j] == false ){
                    int alpha = grid[i][j];
                    vis[i][j] = true;
                    q.push({i,j,-1,-1});
                    if(bfs( grid , alpha  , q , vis )){
                        return true;
                    };

                }
            }
        }
        return false;
    }
};