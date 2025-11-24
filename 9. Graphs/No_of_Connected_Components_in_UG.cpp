class Solution {
public:
    void dfs(int node, vector<int>& vis, vector<vector<int>>& adj){
        vis[node]=1;
        for(auto it: adj[node]){
            if(!vis[it]){
                dfs(it,vis,adj);
            }
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(auto edge: edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        vector<int> vis(n,0);
        int count=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                count++;
                dfs(i,vis,adj);
            }
        }
        return count;
    }
};

TC - O(v+e)
SC - O(v+e)