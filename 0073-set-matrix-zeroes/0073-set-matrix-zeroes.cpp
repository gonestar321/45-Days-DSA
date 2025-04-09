class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        queue<pair<int,int>> q;
        int n = matrix.size();
        int m = matrix[0].size();

        for( int i = 0; i<n ; i++){
            for( int j = 0 ; j< m ;j++){
                if(matrix[i][j] == 0){
                    q.push({i,j});
                }
            }
        }
        while(!q.empty()){
            pair<int,int> node = q.front();
            int rowNo = node.first;
            int colNo = node.second;
            // int delRow = -rowNo;
            // int delCol = -colNo;
            for(int i = 0 ; i <n ; i++){
                if(matrix[i][colNo]!=0){
                    matrix[i][colNo] = 0;
                }
            }
            for(int i = 0 ; i <m ; i++){
                if(matrix[rowNo][i]!= 0){
                    matrix[rowNo][i] = 0;
                }
            }
            q.pop();
        }
        
    }
};