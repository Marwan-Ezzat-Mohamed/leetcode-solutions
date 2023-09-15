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
    bool ans = true;
    void solve(TreeNode* root,long long l,long long r){
        if(!root) return;
        if ( root->val == r ||root->val == l)ans= false;
        if ( root->val > r)ans= false;
        if ( root->val < l)ans= false;
        
        solve(root->right,root->val,r);
        solve(root->left,l,root->val);
        
    }
    
    bool isValidBST(TreeNode* root) {
        solve(root,-1000000000000,  1000000000000);
        return ans;
    }
};