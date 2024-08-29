#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    void dfs(int stone, vector<vector<int>>& stones, unordered_map<int, vector<int>>& rows, unordered_map<int, vector<int>>& cols, unordered_set<int>& visited) {
        if (visited.count(stone)) return;
        visited.insert(stone);
        
        int x = stones[stone][0];
        int y = stones[stone][1];
        
        // Explore all stones in the same row
        for (int neighbor : rows[x]) {
            dfs(neighbor, stones, rows, cols, visited);
        }
        
        // Explore all stones in the same column
        for (int neighbor : cols[y]) {
            dfs(neighbor, stones, rows, cols, visited);
        }
    }

    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        unordered_map<int, vector<int>> rows, cols;
        
        // Map each stone's row and column to their indices
        for (int i = 0; i < n; ++i) {
            rows[stones[i][0]].push_back(i);
            cols[stones[i][1]].push_back(i);
        }
        
        unordered_set<int> visited;
        int numComponents = 0;
        
        for (int i = 0; i < n; ++i) {
            if (!visited.count(i)) {
                dfs(i, stones, rows, cols, visited);
                numComponents++;
            }
        }
        
        return n - numComponents;
    }
};
