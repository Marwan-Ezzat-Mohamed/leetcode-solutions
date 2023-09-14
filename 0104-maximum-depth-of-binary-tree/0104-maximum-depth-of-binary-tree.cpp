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
    int ans = 0;
     void solve(TreeNode* root,int cnt){
        if(root == NULL){
            ans= max(ans,cnt);
            return;
        }
        solve(root->left,cnt+1);
        solve(root->right,cnt+1);
    }
    
    int maxDepth(TreeNode* root) {
        ans = 0;
        solve(root,0);
        return ans;
    }
};