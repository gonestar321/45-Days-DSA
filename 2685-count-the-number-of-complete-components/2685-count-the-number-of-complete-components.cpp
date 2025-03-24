class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vector<bool> visited(n, false);
        

        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        int count = 0;
        
        for (int i = 0; i < n; i++) {

            if (!visited[i]) {
                unordered_set<int> nodes;
                queue<int> q;
                q.push(i);
                visited[i] = true;
                
                while (!q.empty()) {
                    int node = q.front(); q.pop();
                    nodes.insert(node);
                    for (int neighbor : adj[node]) {
                        if (!visited[neighbor]) {
                            visited[neighbor] = true;
                            q.push(neighbor);
                        }
                    }
                }
                
                // Check if the component is complete
                bool isComplete = true;
                for (int node : nodes) {
                    if (adj[node].size() != nodes.size() - 1) {
                        isComplete = false;
                        break;
                    }
                }
                
                if (isComplete) count++;
            }
        }
        
        return count;
    }
};
