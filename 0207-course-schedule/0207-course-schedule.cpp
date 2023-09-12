class Solution {
public:
    
     bool hasCycle(vector<vector<int>> &adj,int node, vector<int>&vis){
        
        vis[node]=1;

        for(auto child : adj[node]){
            if(!vis[child]){
                
                if(hasCycle(adj,child, vis)){
                    return true;   
                }
                 
            }else if (vis[child]==1) {
                return true;
            }
        }
        
        vis[node]=2;
        // ans.insert(node);
        return false;
        
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        vector<vector<int>> adj(numCourses+1,vector<int>());
        
        for(vector<int> x:  prerequisites){
            int v=x[0],u=x[1];
            adj[u].push_back(v);
        }
 
        vector<int> vis(numCourses, 0);
        
        for(int i = 0; i < numCourses; i++) {
            if(!vis[i]) {
                if(hasCycle(adj,i, vis)) {
                    return false;
                }
            }
        }
        
        return true;
        
    }
};