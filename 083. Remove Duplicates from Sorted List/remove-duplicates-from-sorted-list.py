# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def deleteDuplicates(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        pre = head
        cur = None
        if pre != None:
            cur = pre.next
            
        while cur != None:
            if pre.val == cur.val:
                cur = cur.next
                pre.next = cur
            else:
                pre = cur
                cur = cur.next
                
        return head