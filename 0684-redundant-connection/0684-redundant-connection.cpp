class Solution {
public:
    
    int cnt=1;
    bool hasCycle(vector<vector<int>>& adj ,int node,vector<int>&vis,int source){
        vis[node]=cnt;
        for(auto child : adj[node]){
            if(vis[child]!=cnt){
                if(hasCycle(adj,child,vis,source)){
                    return true;
                }
            }
            else if(source==node){
                return true;
            }
        }
        
        return false;
        
            
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n= edges.size();
        vector<vector<int>> adj(n,vector<int>());
        vector<int>vis(n,0);
        reverse(adj.begin(), adj.end());

        
        for(auto e : edges){
            int v=e[0]-1,u=e[1]-1;
            adj[u].push_back(v);
            adj[v].push_back(u);
            
            if(hasCycle(adj,u,vis,u)){
                return e;
            }
            cnt++;
            
        }
        
        
        
        return {};
    }
};