#include <queue> 
class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(int i = 0; i < edges.size(); i++){ // build adj list
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        int totalCount = 0;
        for(int i= 0; i < adj.size(); i++){
            if(adj[i].empty()) totalCount ++; //for the individual ones
        }
        for(int i= 0; i < adj.size(); i++){
            if(adj[i].empty()) continue;
            destroyGraph(adj, adj[i].back());
            totalCount ++;
        }
        return totalCount;
    }

    void destroyGraph(vector<vector<int>> & adj, int initalNode){
        if(adj[initalNode].empty()) return;
        while(!adj[initalNode].empty()){
            //pop.
            int node = adj[initalNode].back();
            adj[initalNode].pop_back();
            destroyGraph(adj, node); 
        }
        return;
    }
};
