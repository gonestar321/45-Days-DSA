#include <vector>
#include <queue>
#include <unordered_map>
#include <limits>
using namespace std;

class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        // Adjacency list to store graph
        vector<vector<pair<int, double>>> graph(n);
        for (int i = 0; i < edges.size(); ++i) {
            int u = edges[i][0];
            int v = edges[i][1];
            double prob = succProb[i];
            graph[u].emplace_back(v, prob);
            graph[v].emplace_back(u, prob);
        }

        // Max-heap (priority queue)
        priority_queue<pair<double, int>> pq;
        vector<double> probabilities(n, 0.0);
        probabilities[start_node] = 1.0;
        pq.push({1.0, start_node});

        while (!pq.empty()) {
            double prob = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            if (node == end_node) {
                return prob;
            }

            for (auto& neighbor : graph[node]) {
                int next_node = neighbor.first;
                double edge_prob = neighbor.second;
                double new_prob = prob * edge_prob;
                if (new_prob > probabilities[next_node]) {
                    probabilities[next_node] = new_prob;
                    pq.push({new_prob, next_node});
                }
            }
        }

        // If the end_node is unreachable
        return 0.0;
    }
};
