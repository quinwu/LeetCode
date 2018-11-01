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
    
    void dfs(TreeNode* root, vector<int>& v, vector<vector<int>>& ans, int sum){
        
        v.push_back(root->val);
        int res = sum - root->val;
        if( root->left == NULL && root->right == NULL){
            if(res == 0){
                ans.push_back(v);
            }
        }
        
        if(root->left != NULL){
            dfs(root->left, v, ans, res);
        }
        if(root->right != NULL){
            dfs(root->right, v, ans, res);
        }
        
        v.pop_back();
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> ans;
        if(root==NULL){
            return ans;
        }
        vector<int> v;
        dfs(root, v, ans, sum);
        return ans;
    }   
};