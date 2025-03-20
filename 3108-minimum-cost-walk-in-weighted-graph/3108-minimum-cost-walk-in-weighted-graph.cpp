#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        vector<int> result;
        unordered_map<int, vector<pair<int, int>>> graph;
        vector<int> component(n, -1);
        vector<int> min_edge(n, INT_MAX);
        int comp_id = 0;

        // Build the graph
        for (auto& edge : edges) {
            int u = edge[0], v = edge[1], w = edge[2];
            graph[u].emplace_back(v, w);
            graph[v].emplace_back(u, w);
        }

        // BFS to find connected components and minimum edge weight in each component
        for (int i = 0; i < n; i++) {
            if (component[i] == -1) {
                queue<int> q;
                q.push(i);
                component[i] = comp_id;
                int min_w = INT_MAX;

                while (!q.empty()) {
                    int node = q.front();
                    q.pop();

                    for (auto& [neighbor, weight] : graph[node]) {
                        min_w &= weight;
                        if (component[neighbor] == -1) {
                            component[neighbor] = comp_id;
                            q.push(neighbor);
                        }
                    }
                }
                min_edge[comp_id++] = min_w;
            }
        }

        // Process queries
        for (auto& q : query) {
            int s = q[0], t = q[1];
            if (component[s] != component[t]) {
                result.push_back(-1);
            } else {
                result.push_back(min_edge[component[s]]);
            }
        }

        return result;
    }
};
