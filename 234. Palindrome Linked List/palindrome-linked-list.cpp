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
    
    ListNode* reverseList(ListNode* head) {
        ListNode* ans = NULL;
        if(!head){
            return ans;
        }
        ListNode* iter = head;
        ListNode* p = NULL;
        while(iter){
            ListNode* q = new ListNode(iter->val);
            q->next = p;
            ans = q;
            p = q;
            
            iter = iter->next;
            
        }
        return ans;
    }
    
    bool isPalindrome(ListNode* head) {
        if(!head || !head->next){
            return true;
        }
        ListNode* q = reverseList(head);
        ListNode* p = head;
        while(p){
            if( p->val != q->val){
                return false;
            }
            p = p->next;
            q = q->next;
        }
        return true;
    }
};