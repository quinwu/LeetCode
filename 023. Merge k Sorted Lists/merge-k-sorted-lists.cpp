/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
public:
    ListNode* merge2Lists(ListNode* a, ListNode* b){
        if(!a){
            return b;
        }
        if(!b){
            return a;
        }
    
        if(a->val <= b-> val){
            a->next = merge2Lists(a->next, b);
            return a;
        }
        else{
            b->next = merge2Lists(a, b->next);
            return b;
        }  
    }
    
    ListNode* mergebinary(vector<ListNode*>& lists, int left, int right){
        if(right < left){
            return NULL;
        }
        if(right == left){
            return lists[left];
        }
        int mid = left + (right - left)/2;
        return merge2Lists(mergebinary(lists, left, mid), mergebinary(lists, mid+1, right));
        
    }
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        return mergebinary(lists, 0, lists.size()-1);
    }
};