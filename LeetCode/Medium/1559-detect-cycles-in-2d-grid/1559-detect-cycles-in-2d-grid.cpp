class Solution {

    private:
    bool callDFS( vector<vector<char>>& grid , int i , int j , int px , int py , vector<vector<bool>>& vis){
        vis[i][j] = true;
        //px. and py hogye immediate parents for every call

        int delRow[] = { 0 , -1 , 0 , 1 };
        int delCol[] = { -1 , 0 , 1 , 0 };
        int n = grid.size();
        int m = grid[0].size();

        for( int k = 0 ; k< 4 ; k++){
            int newRow = i + delRow[k];
            int newCol = j + delCol[k];

            if(newRow >=0 && newRow < n && newCol >= 0 && newCol<m &&
                (newRow != px || newCol != py )&& 
                    grid[newRow][newCol] == grid[i][j] && !vis[newRow][newCol]){
                       if(callDFS( grid , newRow , newCol , i , j , vis)) return true;

            }

            else if( newRow >=0 && newRow < n && newCol >= 0 && newCol<m &&
                (newRow != px || newCol != py )&& 
                    grid[newRow][newCol] == grid[i][j] && vis[newRow][newCol]==true ){
                        return true;
                    }
        }
        return false;
    }


     public:
    bool containsCycle(vector<vector<char>>& grid) {
        //DFS ka code browskii recursion calling krenge

        int n = grid.size();
        int m = grid[0].size();

        vector<vector<bool>> vis(n , vector<bool>(m,false));

        for( int i = 0 ; i < n ; i++){
            for( int j = 0 ;j < m ; j++){
                if(vis[i][j] == false){
                    if( callDFS( grid, i , j , -1 , -1 , vis)) return true;
                }
            }
        }
        return false;

    }
    
};
// //Optimal BFS
//     private:
//     bool bfs(vector<vector<char>>& grid , char target , int i , int j  , vector<vector<bool>>&vis){
//         queue<tuple<int,int,int,int>> q;
//         q.push({i, j , -1 , -1 });
//         int n = grid.size();
//         int m = grid[0].size();
//         int delX[] = { 0 , -1 , 0 , 1 };
//         int delY[] = { -1 , 0 , 1 , 0 };

//         while(!q.empty()){
//             tuple<int,int,int,int> node = q.front();
//             q.pop();
//             auto[ x , y , px, py ] = node;

//                 for( int k = 0 ; k<4 ; k++ ){
//                     int newRow = x + delX[k];
//                     int newCol = y + delY[k];

//                     if( newRow >=0 && newRow < n && newCol >= 0 && newCol < m && 
//                         (newRow!= px || newCol != py ) &&
//                             grid[newRow][newCol] == target && vis[newRow][newCol] == false    
//                         ){
//                             q.push({newRow , newCol , x ,  y });
//                             vis[newRow][newCol] = true;
//                         }
                    
//                     else if ( newRow >=0 && newRow <n && newCol >=0 && newCol <m &&
//                                (newRow != px || newCol != py) &&
//                                grid[newRow][newCol]==target &&vis[newRow][newCol]==true  ){
//                                 return true;
//                                }
//                 }
            
//         }
//         return false;
//     }

//     public:
//     bool containsCycle(vector<vector<char>>& grid) {
//             int n = grid.size();
//             int m = grid[0].size();

//             vector<vector<bool>> vis(n ,  vector<bool>(m,false)); //visited array initialisation

//             for( int i = 0 ; i < n ; i++ ){
//                 for( int  j = 0 ; j < m ; j++){
//                     char target = grid[i][j];
//                     if( !vis[i][j] ){
//                         if(bfs( grid ,target , i , j , vis)) return true;;
//                     }
//                 }
//             }
//             return false;

        


// }
// };
// //BRUTE-BFS 
// // private: 

// //     bool bfs( vector<vector<char>>& grid , char alpha ,
// //              queue<tuple<int,int,int,int>> &q , vector<vector<bool>>& vis ){

// //             // queue is already taken by reference 
// //             int n = grid.size();
// //             int m = grid[0].size();

// //             while( !q.empty() ){
// //                 tuple<int,int,int,int> node = q.front();
// //                 q.pop();

// //                 auto[ x , y , px , py ] = node;

// //                 int delX[] = { 0 , -1 , 0 , 1 };
// //                 int delY[] = { -1 , 0 , 1 , 0 };

// //                 for( int k = 0 ; k < 4 ; k++){
// //                     int nextRow = x + delX[k];
// //                     int nextCol = y + delY[k];


// //                      if(nextRow >= 0 && nextRow < n && nextCol >=0 && nextCol < m && 
// //                                 (nextRow != px || nextCol != py ) &&// out of bounds check
// //                                 grid[nextRow][nextCol]== alpha && !vis[nextRow][nextCol] ){
// //                                          q.push({nextRow , nextCol , x , y});
// //                                          vis[nextRow][nextCol] = true;
// //                                 }
                        
// //                     else if (nextRow >= 0 && nextRow < n && nextCol >= 0 && nextCol < m &&
// //                             vis[nextRow][nextCol] == true &&
// //                             (nextRow != px || nextCol != py) && grid[nextRow][nextCol]== alpha ){
// //                         return true;
// //                     }

                
// //                 }
// //             } 
// //             return false;
// //     }


// // public:
// //     bool containsCycle(vector<vector<char>>& grid) {
        
// //         int n = grid.size();
// //         int m = grid[0].size();

// //         vector<vector<bool>> vis(n, vector<bool>(m,false));

// //         queue<tuple<int,int,int,int>>  q ;
// //         //q.push({x,y, xp , yp}) ;

// //         for( int i = 0 ; i < n ; i ++){
// //             for ( int j = 0 ; j< m ; j++){
// //                 if( vis[i][j] == false ){
// //                     int alpha = grid[i][j];
// //                     vis[i][j] = true;
// //                     q.push({i,j,-1,-1});
// //                     if(bfs( grid , alpha  , q , vis )){
// //                         return true;
// //                     };

// //                 }
// //             }
// //         }
// //         return false;
// //     }
// // };