class Solution {
public:
     vector<int>ans;
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
        ans.push_back(node);
        return false;
        
    }
    
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses,vector<int>());
        ans.clear();
        for(vector<int> x:  prerequisites){
            int v=x[0],u=x[1];
            adj[v].push_back(u);
        }
 
        vector<int> vis(numCourses, 0);
        
        for(int i = 0; i < numCourses; i++) {
            if(!vis[i]) {
                if(hasCycle(adj,i, vis)) {
                    vector<int>e;
                    return e;
                }
            }
        }
        // vector<int>tmp;
        // for(auto x : ans){
        //     tmp.push_back(x);
        // }
        return ans;
        
    }
};