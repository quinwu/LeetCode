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
    int maxDepth(TreeNode* root) {
        int ans = dfs(root,1);
        return ans;
    }
    int dfs(TreeNode* root,int depth){
        
        if (root == NULL){
            return 0;
        }
        
        if (root->left == NULL && root->right == NULL){
            return depth;
        }
        
        int left_depth = 0;
        if (root->left != NULL){
            left_depth = dfs(root->left, depth+1);
        }
        
        int right_depth = 0;
        if (root->right != NULL){
            right_depth = dfs(root->right, depth+1);
        }
        return max(left_depth, right_depth);
    }
};