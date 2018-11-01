/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if(root == NULL){
            return 0;
        }
        int ans = 0;
        dfs(root, false, ans);
        return ans;
    }
    
    void dfs(TreeNode* root,bool is_left,int& ans){
        if(is_left && root->left == NULL && root->right ==NULL){
            ans += root->val;
        }
        
        if(root->left != NULL){
            dfs(root->left, true, ans);
        }
        if(root->right != NULL){
            dfs(root->right, false, ans);
        }
        
    }
    
};