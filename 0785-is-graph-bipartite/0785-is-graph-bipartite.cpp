class Solution {
public:
    bool bfs( int node , vector<vector<int>> &graph , vector<int>& color ){
        queue<int> q; 
        q.push( node );

        while( !q.empty() ){
            int parent = q.front();
            q.pop();
            // adjacent nodes ko push karo )=>

            if( color[parent] == -1 ){
                color[parent] = 0;
            }

            for(int i =0 ; i < graph[parent].size();i++){
                if( color[graph[parent][i]] == color[parent] ){
                    return false;
                }
                else if( color[graph[parent][i]] == -1 ){
                    if(color[parent] == 0){
                        color[graph[parent][i]] = 1 ;
                        q.push(graph[parent][i]);
                    }
                    else{ color[graph[parent][i]] = 0;
                            q.push(graph[parent][i]); }
                }
            
        }
    }
    return true;
    };



    bool isBipartite(vector<vector<int>>& graph) {
        //seedha seedha anuvaad hai ki ye graph 
        // ek adjacency list hai aur kuchh nahin
        int n = graph.size(); 

        vector<bool> vis( n , false);
        vector<int> color( n , -1 );

        for( int i = 0 ; i < n ; i++ ){
            // ye nodes par aagye hum 
            if( color[i] == -1 ){
                if(!bfs( i , graph , color  )){
                    return false;
                };


            }
        }
        return true;
    }
};