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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        
        if(!p && !q){
            return true;
        }
        
        if((p && !q) || (!p && q)){
            return false;
        }
        
        if( !p->left && !p->right && !q->left && !q->right){
            if(p->val == q->val){
                return true;
            }
            else{
                return false;
            }
        }
        
        if(p && q ){
            if(p->val != q->val){
                return false;
            }
            bool left_child = false;
            if(!p->left && !q->left){
                left_child = true;
            }
            if(p->left && q->left){
                left_child = isSameTree(p->left, q->left);
            }
            
            bool right_child = false;
            if(!p->right && !q->right){
                right_child = true;
            }
            if(p->right && q->right){
                right_child = isSameTree(p->right, q->right);
            }
            return left_child && right_child;
        }
    }
};