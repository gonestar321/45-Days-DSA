class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        //BFS chalega bhaisahab lets see what to do 

        int n = grid.size(); // row size
        int m = grid[0].size(); // col size

        vector<vector<bool>> vis( n , vector<bool>(m,false)); // visited copy of grid banadi
        
        queue<pair<int,int>> timeNode;

        for( int i = 0 ; i < n ; i++ ){
            for( int j = 0 ; j< m ; j++ ){

                if( grid[i][j] == 2 ){
                        timeNode.push({i , j});
                        vis[i][j] = true;
                }
            }
        }

        vector<int> dx = { 0 , -1 , 0 , 1 };
        vector<int> dy = { -1 ,0  , 1 , 0 }; // direction vectors initialised

        int globalTime = 0;
        while(!timeNode.empty()){
            

            int nodeSize = timeNode.size();
            

            for( int i = 0 ; i < nodeSize ; i++ ){
                auto [x,y] = timeNode.front();
                timeNode.pop();

                for( int i = 0 ;  i < 4 ; i++ ){ //per node ka 4-D checker
                    int ny = y + dy[i];
                    int nx = x + dx[i];

                    if( nx >=0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] == 1 && 
                            !vis[nx][ny] ){
                        timeNode.push({nx , ny });
                        grid[nx][ny] = 2;
                        vis[nx][ny] = true;
                    }
                }
                

            }
            if( !timeNode.empty() ){
                globalTime++;
            }
            

        }

        for( int i = 0 ; i < n ; i++){
            for( int j = 0 ; j < m ; j++ ){
                if( grid[i][j] == 1){
                    return -1;
                }
        }
        }
        
        return globalTime;



    }
};