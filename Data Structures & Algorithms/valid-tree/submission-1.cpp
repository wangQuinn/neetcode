#include <unordered_set>

using namespace std;

class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {

        if (edges.size() != n - 1) return false;


        vector<vector<int>> adj(n);
        for (const auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]); // Undirected graph
        }

        unordered_set<int> visited;

        if (hasCycle(adj, visited, 0, -1)) return false;

        return visited.size() == n;
    }

private:
    bool hasCycle(const vector<vector<int>>& adj, unordered_set<int>& visited, int node, int parent) {
        visited.insert(node);

        for (int neighbor : adj[node]) {
            if (neighbor == parent) continue; 

            if (visited.count(neighbor)) return true; 

            if (hasCycle(adj, visited, neighbor, node)) return true;
        }

        return false;
    }
};
