/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
  public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        if (l1 == NULL)
        {
            return l2;
        }
        if (l2 == NULL)
        {
            return l1;
        }

        ListNode *list = NULL;

        if (l1->val <= l2->val)
        {
            list = new ListNode(l1->val);
            l1 = l1->next;
        }
        else
        {
            list = new ListNode(l2->val);
            l2 = l2->next;
        }

        ListNode *head = list;

        while (l1 != NULL && l2 != NULL)
        {
            if (l1->val <= l2->val)
            {
                list->next = new ListNode(l1->val);
                l1 = l1->next;
                list = list->next;
            }
            else
            {
                list->next = new ListNode(l2->val);
                l2 = l2->next;
                list = list->next;
            }
        }

        while (l1 != NULL)
        {
            list->next = new ListNode(l1->val);
            l1 = l1->next;
            list = list->next;
        }

        while (l2 != NULL)
        {
            list->next = new ListNode(l2->val);
            l2 = l2->next;
            list = list->next;
        }
        return head;
    }
};