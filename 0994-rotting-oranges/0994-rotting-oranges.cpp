class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        

        int n = grid.size();
        int m = grid[0].size();

        vector<vector<bool>> vis(n, vector<bool>(m,false));
        queue<tuple<int,int,int>> q;
        for( int i = 0 ; i < n ; i++){
            for( int j = 0 ; j < m ; j++){
                if(grid[i][j] == 2){
                    q.push({i,j,0});
                }
            }
        }

        int maxTime =0;
        while(!q.empty()){
            tuple<int,int,int> node = q.front();

            q.pop();

            auto[row , col , time] = node;
            maxTime = max(maxTime , time);

            int delRow[] = { -1 , 0 , 1 , 0 };
            int delCol[] = { 0 , -1 , 0 , 1 };

            for( int k = 0 ; k < 4 ; k++){
                int newRow = row + delRow[k];
                int newCol = col + delCol[k];

                if( newRow >= 0 && newRow <n && newCol >=0 && newCol <m
                    && grid[newRow][newCol] == 1 && vis[newRow][newCol]==false){

                        q.push({ newRow , newCol , time+1});
                        vis[newRow][newCol] = true;
                        grid[newRow][newCol] = 2;

                }

            }
        

    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 1) return -1;
        }
    }
return maxTime;
    }
};