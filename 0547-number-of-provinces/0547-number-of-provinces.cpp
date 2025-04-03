class Solution {
public:

//DFS karte hain revise.

    void countProvince( vector<vector<int>>& isConnected , vector<bool>&vis , int i ){

            vis[i] =true;

            for( int x = 0 ; x<isConnected.size() ; x++){
                if(isConnected[i][x]==1 && vis[x]==false){
                    countProvince(isConnected , vis , x);
                }
            }
            
    }






    int findCircleNum(vector<vector<int>>& isConnected) {
        // isConnected is the adjacency list
        // we need to make a visited 2D array

        int n = isConnected.size();
        
        int num = 0;
        vector<bool> vis(n,false);

        for( int i =0 ; i<n ; i++){
                if(vis[i]==false){
                    countProvince(isConnected , vis , i );
                    num++;
                }
                
        }
        return num;
    }
};