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
    bool hasPathSum(TreeNode* root, int sum) {
        if(root == NULL){
            return false;
        }
        if(root->left == NULL && root->right == NULL){
            if(root->val == sum){
                return true;
            }
            else{
                return false;
            }
        }
        int child_sum = sum - root->val;
        return hasPathSum(root->left, child_sum) || hasPathSum(root->right, child_sum);
    }
};