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


    void solve(TreeNode* root,int depth,vector<vector<int>>&ans){
        if(!root)return;
        if (depth<ans.size()){
            ans[depth].push_back(root->val);
        }
        else {
            ans.resize(depth+1,{root->val});
        }
        
        solve(root->left,depth+1,ans);
        solve(root->right,depth+1,ans);  
        
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        solve(root,0,ans);
        
        return ans;
    }
};