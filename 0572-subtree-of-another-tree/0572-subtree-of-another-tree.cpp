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
    bool ans = false;
     bool solve(TreeNode* p, TreeNode* q){
        if(!p and !q){
            return true;
        }
        else if(!p || !q)return false;
        if(p->val!=q->val){
            return false;
        }
        
        return solve(p->right,q->right) && solve(p->left,q->left);
        
    }
    bool solve1(TreeNode* root,TreeNode* subRoot){
        if(!root){
            if(!subRoot)return true;
            return false;
        }
        if(root->val==subRoot->val){
            if(!ans && solve(root,subRoot))
            ans=true;
        }
        
        solve1(root->right,subRoot);
        solve1(root->left,subRoot);
        
        return ans;
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        return solve1(root,subRoot);
    }
};