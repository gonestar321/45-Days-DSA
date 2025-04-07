class Solution {
public:

// //DFS Revision.

//     void countProvince( vector<vector<int>>& isConnected , vector<bool>&vis , int i ){

//             vis[i] =true;

//             for( int x = 0 ; x<isConnected.size() ; x++){
//                 if(isConnected[i][x]==1 && vis[x]==false){
//                     countProvince(isConnected , vis , x);
//                 }
//             }
            
//     }






//     int findCircleNum(vector<vector<int>>& isConnected) {
//         // isConnected is the adjacency list
//         // we need to make a visited 2D array

//         int n = isConnected.size();
        
//         int num = 0;
//         vector<bool> vis(n,false);

//         for( int i =0 ; i<n ; i++){
//                 if(vis[i]==false){
//                     countProvince(isConnected , vis , i );
//                     num++;
//                 }
                
//         }
//         return num;
//     }


//BFS revision chalo LESSGO

    void bfs( vector<vector<int>>& isConnected ,  vector<bool> & vis , int i ){
        vis[i] = true;
        queue<int> q; 
        q.push(i);
       

        while(!q.empty()){

        int node = q.front();
        q.pop();
            for( int j = 0; j<isConnected.size(); j++ ){
                if(isConnected[node][j]==1 && vis[j] == false){
                    q.push(j);
                    vis[j] = true;
                }
            }
        }
    }


    int findCircleNum(vector<vector<int>>& isConnected) {

        int n = isConnected.size();
        // cout<<n<<endl;
        vector<bool> vis(n , false );
        int provinces = 0;

        for( int i = 0 ; i < n ; i++){
            if(vis[i] == false){
                provinces++;
                bfs(isConnected , vis , i);
            }
        }
        return provinces;
    }
};