class Solution {
public:
    void solve(vector<vector<char>>& board) {
        
        int n = board.size();
        int m = board[0].size();

        vector<vector<bool>> vis( n , vector<bool>(m,false));

        queue<pair<int,int>> q; 
        
        // top row & bottom row scan karo
        for( int i = 0 ; i < m ; i++){
            if( board[0][i] == 'O' && vis[0][i] == false){
                vis[0][i] = true;
                q.push({0,i});
            }

            if( board[n-1][i] == 'O' && vis[n-1][i] == false){
                vis[n-1][i] = true;
                q.push({n-1 , i});
            }
        }

        //left-most column and right most columns scan
        
        for( int i = 0 ; i < n ; i++){
            if( board[i][0] == 'O' && vis[i][0] == false){
                vis[i][0] = true;
                q.push({i , 0});
            }

            if( board[i][m-1] == 'O' && vis[i][m-1] == false){
                vis[i][m-1] = true;
                q.push({i , m-1});
            }
        }

        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            int direction[] = { 0 , -1 , 0 , 1 , 0};

            for( int i = 0 ; i < 4 ; i++){
                int nRow =  row + direction[i];
                int nCol = col + direction[i+1];

                if(nRow>=0 && nRow<n && nCol >= 0 && nCol < m && board[nRow][nCol] == 'O' && vis[nRow][nCol] == false){
                    q.push({nRow , nCol});
                    vis[nRow][nCol] = true;
                }
            }
        }

        for( int i = 0 ; i < n ; i++){
            for ( int j = 0 ; j < m ; j++){
                 if (board[i][j] == 'O' && vis[i][j] == false) {
                     board[i][j] = 'X';  // ❗ Only flip unsafe 'O'
                }
            }
        }

  
    }   
};