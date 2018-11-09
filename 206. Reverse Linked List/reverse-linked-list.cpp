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
};