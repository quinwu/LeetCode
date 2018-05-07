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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = l1;
        ListNode* p = NULL;
        while (l1 != NULL && l2 != NULL){
            p = l1;
            l1->val += l2->val;
            l1 = l1->next;
            l2 = l2->next;
        }
        
        if (l2 != NULL){
            p->next = l2;
        }
        
        p = head;
        while( p->next != NULL){
            if ( p->val > 9){
                p->next->val += p->val / 10;
                p->val = p->val % 10;
            }
            p = p->next;
        }
        if (p->val > 9){
            p->next = new ListNode(p->val / 10);
            p->val = p->val % 10;
        }

        return head;
    }
};