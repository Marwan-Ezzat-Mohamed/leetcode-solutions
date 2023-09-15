/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxDepth=0;
    
    
    void setDepth(TreeNode* root,int depth){
        if(!root)return;
        
        maxDepth = max(depth,maxDepth);
        setDepth(root->left,depth+1);
        setDepth(root->right,depth+1);  
    }

    void solve(TreeNode* root,int depth,vector<vector<int>>&ans){
        if(!root)return;
        
        maxDepth = max(depth,maxDepth);
        ans[depth].push_back(root->val);
        solve(root->left,depth+1,ans);
        solve(root->right,depth+1,ans);  
        
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        setDepth(root,0);
        // cout<<maxDepth;
        vector<vector<int>>ans(maxDepth+1);
         
        solve(root,0,ans);
        for(int i=0;i<ans.size();i++){
            if(ans[i].size()==0){
                ans.erase(ans.begin()+i);
            }
        }
        return ans;
    }
};