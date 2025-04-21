class Solution {
public:
    bool bfs( int node , vector<vector<int>>&graph , vector<int>& color ){

        queue<int> q;
        q.push(node);
        color[node] = 0;

        while(!q.empty()){
            int parent = q.front();
            q.pop();

            for( int i = 0 ; i< graph[parent].size() ; i++ ){
                int child = graph[parent][i];

                if( color[parent] == color[child] ){
                        return false;
                }
                else if(color[parent] == 0 && color[child] == -1){
                    color[child] = 1;
                    q.push(child);
                }
                else if( color[parent]==1 && color[child] == -1){
                    color[child] = 0;
                    q.push(child);
                }
            }
        }
        return true;
        
    }
    bool isBipartite(vector<vector<int>>& graph) {
        // kal karliya thhaa
        // hogaya thha...
        // hojayegaa

        int n = graph.size();

        vector<int> color( n , -1);

            for( int i = 0 ; i < n ; i++ ){
                if(color[i] == -1){
                    if(!bfs(i , graph , color)){
                        return false;
                    }
                }
            }
            return true;
    }
};