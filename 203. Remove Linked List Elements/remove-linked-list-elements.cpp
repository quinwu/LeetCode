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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* p = head;
        if (p == NULL){
            return NULL;
        }
        // delete head node
        while(p && p->val == val){
            head = p->next;
            p = head;
        }
        ListNode* q = NULL; 
        if(p){
            q = p->next; 
        }
        while(q){
            if(q->val == val){
                p->next = q->next;
                q = p->next;
            }
            else{
                p = p->next;
                q = q->next;
            }
        }
        return head;
    }
};