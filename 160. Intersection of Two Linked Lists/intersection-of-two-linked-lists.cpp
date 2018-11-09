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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lenA = 0;
        int lenB = 0;
        ListNode* p = headA;
        while(p){
            lenA ++;
            p = p->next;
        }
        ListNode* q = headB;
        while(q){
            lenB ++;
            q = q->next;
        }
        p = headA;
        q = headB;
        while(lenA > lenB){
            lenA --;
            p = p->next;
        }
        while(lenA < lenB){
            lenB --;
            q = q->next;
        }
        while(p && q){
            if (p == q){
                return p;
            }
            p = p->next;
            q = q->next;
        }
        return NULL;
    }
};